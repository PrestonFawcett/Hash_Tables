#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ItemPallet.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int sku) {
  // TODO: implement this function, then delete the return statement below
	return sku / 100000;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below
	return sku / 10000 % 10;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below
	return sku / 1000 % 10;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below
	return sku / 100 % 10;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int sku) {
    // TODO: implement this function, then delete the return statement below
	return sku / 10 % 10;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct6(unsigned int sku) {
    // TODO: implement this function, then delete the return statement below
	return sku % 10;
}

// Constructor for struct Item
Item::Item(string itemName, unsigned int sku):itemName_(itemName), sku_(sku)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemPallet::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemName;
    unsigned int sku;
    while (myfile >> itemName >> sku) {
			if (itemName.size() > 0)
      	addItem(itemName, sku);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemPallet::addItem(string itemName, unsigned int sku) {
  // TO BE COMPLETED
  // function that adds the specified SKU to the pallet (i.e., to all hash tables)
  Item new_item(itemName, sku);
  hT1.insert(std::make_pair(sku, new_item));
  hT2.insert(std::make_pair(sku, new_item));
  hT3.insert(std::make_pair(sku, new_item));
  hT4.insert(std::make_pair(sku, new_item));
  hT5.insert(std::make_pair(sku, new_item));
  hT6.insert(std::make_pair(sku, new_item));
}

bool ItemPallet::removeItem(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below

  // function that removes the pair of glasses specified by the sku from the display
  // if pair is found, then it is removed and the function returns true
  // else returns false

    return true;
}

unsigned int ItemPallet::bestHashing() {
  // TODO: implement this function, then delete the return statement below
    
  // function that decides the best has function, i.e. the ones among
  // fct1-fct6 that creates the most balanced hash table for the current
  // ItemPallet data member allItems

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/
	// Then, calculate the lowest balance
  unsigned int min, max = hT1.bucket_size(0);
  for (auto i = 1; i < 10; i++) {
    if (hT1.bucket_size(i) < min)
      min = hT1.bucket_size(i);
    else if (hT1.bucket_size(i) > max)
      max = hT1.bucket_size(i);
  }
  unsigned int best = max - min;
  
  min, max = hT2.bucket_size(0);
  for (auto i = 1; i < 10; i++) {
    if (hT2.bucket_size(i) < min)
      min = hT2.bucket_size(i);
    else if (hT2.bucket_size(i) > max)
      max = hT2.bucket_size(i);
  }
  if (max - min < best)
    best = max - min;
  
  min, max = hT3.bucket_size(0);
  for (auto i = 1; i < 10; i++) {
    if (hT3.bucket_size(i) < min)
      min = hT3.bucket_size(i);
    else if (hT3.bucket_size(i) > max)
      max = hT3.bucket_size(i);
  }
  if (max - min < best)
    best = max - min;

  min, max = hT4.bucket_size(0);
  for (auto i = 1; i < 10; i++) {
    if (hT4.bucket_size(i) < min)
      min = hT4.bucket_size(i);
    else if (hT4.bucket_size(i) > max)
      max = hT4.bucket_size(i);
  }
  if (max - min < best)
    best = max - min;

  min, max = hT5.bucket_size(0);
  for (auto i = 1; i < 10; i++) {
    if (hT5.bucket_size(i) < min)
      min = hT5.bucket_size(i);
    else if (hT5.bucket_size(i) > max)
      max = hT5.bucket_size(i);
  }
  if (max - min < best)
    best = max - min;

  min, max = hT6.bucket_size(0);
  for (auto i = 1; i < 10; i++) {
    if (hT6.bucket_size(i) < min)
      min = hT6.bucket_size(i);
    else if (hT6.bucket_size(i) > max)
      max = hT6.bucket_size(i);
  }
  if (max - min < best)
    best = max - min;

  return best;

}

// ALREADY COMPLETED
size_t ItemPallet::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) )
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}
