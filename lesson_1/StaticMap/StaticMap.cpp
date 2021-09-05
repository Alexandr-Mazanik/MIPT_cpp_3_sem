#include <iostream>
#include <vector>
#include <algorithm>

struct DictElement{
	int key;
	int value;
};

bool comp(DictElement a, DictElement b){
	return a.key < b.key;
}

int Search_Binary (std::vector<DictElement> & arr, int left, int right, int key){
	int midd = 0;
	while (true) {
		midd = (left + right) / 2;
	 
		if (key < arr[midd].key)       
			right = midd - 1;      
	 	else if (key > arr[midd].key)  
	 		left = midd + 1;    
	 	else                      
	 		return midd;           
	 
	 	if (left > right)         
	 		return -1;	
 	}
}

class StaticMap{
private:
	std::vector<DictElement> static_map_el_;
public:
	StaticMap() = delete;
	StaticMap(std::vector<DictElement> vector){
		std::sort(vector.begin(), vector.end(), comp);
		static_map_el_ = vector;
	}
	int Get(int key, int default_value){
		int index = Search_Binary(static_map_el_, 0, static_map_el_.size(), key);
		if (index != -1)
			return static_map_el_[index].value;
		else
			return default_value;
	}
	bool FindKey(int key){
		int index = Search_Binary(static_map_el_, 0, static_map_el_.size(), key);
		if (index != -1)
			return true;
		else
			return false;
	}
	void show(){
		std::cout << std::endl;
		for (int i=0; i < static_map_el_.size(); ++i)
			std::cout << static_map_el_[i].key << " " << static_map_el_[i].value << std::endl;
		std::cout << std::endl;
	}
};


int main(){
	std::vector<DictElement> vector = {{11, 32}, {42, 14}, {53, 13}, {85, 23}, {19, 35}, {-23, 44}, {0, 23}};
	//std::cout << vector[1].value << std::endl;
	StaticMap static_map(vector);
	static_map.show();
	std::cout << "Enter key:\n";
	int key;
	std::cin >> key;
	if (static_map.FindKey(key))
		std::cout << "Yes, such a key exists" << std::endl;
	else
		std::cout << "No, such a key does not exist" << std::endl;
	std::cout << "Key received " << static_map.Get(key, 666) << std::endl;
	return 0;
}