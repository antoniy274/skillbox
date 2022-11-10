#include "elf_village_2.0.h"


Branch::Branch(Branch* branch){
	this->parent = branch;
}

Branch::Branch() 
{
}

Branch::~Branch()
{
	for (auto i = 0; i < children.size(); ++i) {
		delete children[i];
	}
}

Tree::Tree() {
	int bigBranchs = randomInt(3, 5);
	for (int i = 0; i < bigBranchs; ++i) {
		auto big = new Branch(this);
			
		int mediumBranchs = randomInt(2, 3);
		for (int j = 0; j < mediumBranchs; ++j) {
			big->children.push_back(new Branch(big));
		}

		this->children.push_back(big);
	}
}

void  Tree::askNames(){
	std::string buffer;
	for (int i = 0; i < children.size(); ++i) {
		buffer.clear();
		std::cin >> buffer;
		if (buffer != "None") {
			children[i]->name = buffer;
		}

		for (int j = 0; j < children[i]->children.size(); ++j) {
			buffer.clear();
			std::cin >> buffer;
			if (buffer != "None") {
				children[i]->children[j]->name = buffer;
			}
		}
	}
};


int Tree::findName(std::string buffer) {
	Branch* elf;
	for (int i = 0; i < children.size(); ++i) {
		if (children[i]->name == buffer) {
			elf = children[i];
			break;
		}
		for (int j = 0; j < children[i]->children.size(); ++j) {
			if (children[i]->children[j]->name == buffer) {
				elf = children[i];
				goto elfFound;
			}
		}
	}
elfFound:
	int count = 0;
	if (elf->parent == this) {
		for (int i = 0; i < elf->children.size(); ++i) {
			if (!elf->children[i]->name.empty()){
				count++;
			}
		}
	}

	else {
		for (int i = 0; i < elf->parent->children.size(); ++i) {
			if (!elf->parent->children[i]->name.empty()) {
				count++;
			}
		}
		if (!elf->parent->name.empty()) {
			count++;
		}
	}
	return count;
}