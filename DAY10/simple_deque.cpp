#include<iostream>
using namespace std;

class simpleDeque{
	static const int BLOCK_SIZE = 4;
	static const int TABLE_SIZE = 4;
	
	int start_offset;
	int** block_table;
	int end_offset;
	int start_block;
	int end_block;
	int current_size;
	public:
		simpleDeque(){
			block_table = new int*[TABLE_SIZE];
	
			for(int i=0; i<TABLE_SIZE; i++){
				block_table[i] = nullptr;
			}	
			start_block = end_block = TABLE_SIZE/2;
			block_table[start_block] = new int [BLOCK_SIZE];
			start_offset = 0;
			end_offset = 0;
			current_size = 0;
		}

	void push_back(int value){
		if(end_offset == BLOCK_SIZE){
			end_block++;
			block_table[end_block] = new int[BLOCK_SIZE];
			end_offset = 0;
		}
		block_table[end_block][end_offset++] = value;
		current_size++;
	}

	void push_front(int value) {
		if(start_offset > 0){
			start_offset--;
		}
		else{
			start_block--;
			block_table[start_block] = new int[ BLOCK_SIZE ];
			start_offset = BLOCK_SIZE - 1;
			block_table[start_block][start_offset] = value;
			
		}
			
			


	}

	int operator [] (int index) { 
		int total_offset = start_offset + index;
		int block = start_block + (total_offset / BLOCK_SIZE);
		int offset = total_offset % BLOCK_SIZE;
		return block_table[block][offset];
	}


	int size()const {
		return current_size;
	}
};

int main() {

	simpleDeque dobj;
	
	//dobj.push_back(10);
	for(int i=0; i<=5; i++) {
		dobj.push_back(i*10);
	}
	
	for(int i=0; i<5; i++) {
		cout<<dobj[i]<<" ";
	} cout<<endl;



	return 0;
}

