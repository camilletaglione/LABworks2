#ifndef PROBLEM2_H
#define PROBLEM2_H
namespace problem2 {

	int cesarmain();
	string message;
	string mappedKey;
	void messageAndKey();
	int tableArr[26][26];
	void createVigenereTable();
	void cipherEncryption(string message, string mappedKey);
	int itrCount(int key, int msg);
	void cipherDecryption(string message, string mappedKey);
	int decrymain();
}
#endif // PROBLEM2_H
