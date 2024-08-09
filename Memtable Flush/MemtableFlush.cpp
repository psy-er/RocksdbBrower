#include <iostream>
#include <rocksdb/db.h>
#include <rocksdb/status.h>

using namespace std;
using namespace rocksdb;

int main() {

	rocksdb::DB* db;
	rocksdb::Options options;
	options.create_if_missing = true;

	// Rocksdb ����
	rocksdb::Status status = rocksdb::DB::Open(options, "test", &db);
	if (!status.ok()) {
		cerr << "Unable to open RocksDB: " << status.ToString() << endl;
		return 1;
	}

	// Memtable Flush ����
	status = db->Flush(rocksdb::FlushOptions());
	if (!status.ok()) {
		cerr << "Fail to flush memtable" << status.ToString() << endl;
	}
	else {
		cout << "Success to flush memtable" << endl;
	}
	
	delete db;
	return 0;

}