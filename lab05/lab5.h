// Preston Giorgianni
// 861161781
// 5/11/15

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
using namespace std;
#define nil 0
bool back = false;

// #define Value int // restore for testing.
template < typename Value >
class BST {
	class Node 
	{ // binary tree node
	
	public:
		Value value;
		bool selected;
		Node* left;
		Node* right;
		
		Node( const Value v = Value() )
		: value(v), left(nil), right(nil), selected(false)
		{}
		Value& content() { return value; }
		bool isInternal() { return left != nil && right != nil; }
		bool isExternal() { return left != nil || right != nil; }
		bool isLeaf() { return left == nil && right == nil; }
		int height() 
		{
			// returns the height of the subtree rooted at this node
			// FILL IN
			int one = 0;
			int two = 0;
			if(this == nil || (left == nil && right == nil))
			{
				return 0;
			}
			if(left != nil)
			{
				one = left->height();
			}
			if(right != nil)
			{
				two = right->height();
			}
			if(one > two)
			{
				return one + 1;
			}
			else
			{
				return two + 1;
			}
		}
		
		int size() 
		{
			// returns the size of the subtree rooted at this node,
			// FILL IN
			if(this == nil)//empty check
			{
				return 0;
			}
			else if(left == nil && right == nil)//no childeren check
			{
				return 1;
			}
			int out = 1;
			if(left != nil)//prevent seg fault if 1 child
			{
				out += left->size();
			}
			if(right != nil)//prevent seg fault if 1 chils
			{
				out += right->size();
			}
			return out;
		}
	}; // Node

	// const Node* nil; // later nil will point to a sentinel node.
	private:
	Node* root;
	
	public:
	int size() 
	{
		// size of the overall tree.
		// FILL IN
		return root->size();
	}
	bool empty() { return size() == 0; }
	
	void print_node( const Node* n ) const 
	{
		// Print the node’s value.
		// FILL IN
		cout << n->value;
	}
	
	bool search ( Value x )
	{
		// search for a Value in the BST and return true iff it was found.
		// FILL IN
		//goes left or right based on value until it hits the end
		Node* temp = root;
		while(temp != nil)
		{
			if(temp->value == x)
			{
				return true;
			}
			else if(temp->value > x)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		return false;
	}
	
	void preorder()const 
	{
		// Traverse and print the tree one Value per line in preorder.
		// FILL IN
		if(root == nil) return;
		printPre(root);
	}
	
	void printPre(Node* temp) const
	{
		//helper printing with print node value
		print_node(temp);
		cout << endl;
		if(temp->left != nil)
		{
			printPre(temp->left);
		}
		if(temp->right != nil)
		{
			printPre(temp->right);
		}
	}
	
	void postorder()const
	{
		// Traverse and print the tree one Value per line in postorder.
		// FILL IN
		if(root == nil) return;
		printPost(root);
	}
	
	void printPost(Node* temp) const
	{
		//helper printing with print node value
		if(temp->left != nil)
		{
			printPost(temp->left);
		}
		if(temp->right != nil)
		{
			printPost(temp->right);
		}
		print_node(temp);
		cout << endl;
	}
	
	void inorder()const
	{
		// Traverse and print the tree one Value per line in inorder.
		// FILL IN
		if(root == nil) return;
		printIn(root);
	}
	
	void printIn(const Node* temp) const
	{
		//helper printing with print node value
		if(temp->left != nil)
		{
			printIn(temp->left);
		}
		print_node(temp);
		cout << endl;
		if(temp->right != nil)
		{
			printIn(temp->right);
		}
	}
	
	Value& operator[] (int n)
	{
		// returns reference to the value field of the n-th Node.
		// FILL IN
		//uses helper with pointers to find value
		assert(n >= size() || n < 0);
		int location = 0;
		Value final;
		return braket(n, location, root, final);
	}
	
	Value& braket(int n,int& location, Node* temp, Value& final)
	{
		if(temp->left != nil)
		{
			braket(n, location, temp->left, final);
		}
		if(location == n)
		{
			final = temp->value;
		}
		location += 1;
		if(temp->right != nil)
		{
			braket(n, location, temp->right, final);
		}
		return final;
	}
	
	BST() : root(nil) {}
	
	void insert( Value X ) { root = insert( X, root ); }
	Node* insert( Value X, Node* T )
	{
		// The normal binary-tree insertion procedure ...
		if ( T == nil )
		{
			T = new Node( X ); // the only place that T gets updated.
		}
		else if ( X < T->value )
		{
			T->left = insert( X, T->left );
		}
		else if ( X > T->value )
		{
			T->right = insert( X, T->right );
		} 
		else
		{
			T->value = X;
		}
		// later, rebalancing code will be installed here 3
		return T;
	}
	
	void remove( Value X ) { root = remove( X, root ); }
	
	Node* remove( Value X, Node*& T )
	{
		// The normal binary-tree removal procedure ...
		// Weiss’s code is faster but way more intricate.
		if ( T != nil )
		{
			if ( X > T->value )
			{
				T->right = remove( X, T->right );
			}
			else if ( X < T->value )
			{
				T->left = remove( X, T->left );
			}
			else
			{ // X == T->value
				if ( T->right != nil )
				{
					Node* x = T->right;
					while ( x->left != nil ) x = x->left;
					T->value = x->value; // successor’s value
					T->right = remove( T->value, T->right );
				}
				else if ( T->left != nil )
				{
					Node* x = T->left;
					while ( x->right != nil ) x = x->right;
					T->value = x->value; // predecessor’s value
					T->left = remove( T->value, T->left );
				}
				else
				{ // *T is external
					delete T;
					T = nil; // the only updating of T
				}
			}
		}
		// later, rebalancing code will be installed here
		return T;
	}

	void okay( ) { okay( root ); }
	
	void okay( Node* T )
	{
	// diagnostic code can be installed here
	return;
	}
	
	//uses a static int to keep track of were the iteration is at
	//adds elements to that spot in array and checks if there is a sum path
	//when it finds the sum path it outputs and returns true
	void findSumPath(Node* n, int num, int buffer[])
    {
    	if(n == nil)
    	{
    		if(n == root)
    		{
    			cout << 0 << endl;
    		}
    		return;
    	}
    	static int iteration = -1;
    	if(n == root)
    	{
    		back = false;
    	}
    	++iteration;
    	// cout << "start: " << iteration << endl;
    	buffer[iteration] = n->value;
    	int sum = 0;
    	for(int i = 0; i <= iteration; ++i)
    	{
    		sum += buffer[i];
    	}
    	if(sum == num && n->left == nil && n->right == nil)
    	{
    		back = true;
    		for(int i = 0; i <= iteration; ++i)
    		{
    			cout << buffer[i] << ' ';
    		}
    		cout << endl;
    	}
    	if(n->left != nil)
    	{
    		findSumPath(n->left, num, buffer);
    	}
    	if(n->right != nil)
    	{
    		findSumPath(n->right, num, buffer);
    	}
    	--iteration;
    	// cout << "end: " << iteration << endl;
    	if(n == root && back == false)
    	{
    		cout << 0 << endl;
    	}
    	return;
    }
    
    //uses turned findSumpath into a helper because you do no have acess to a node
    void SumPath(int n)
    {
    	cout << "Part 2" << endl;
    	int buffer[1000];
    	findSumPath(root, n, buffer);
    	return;
    }
    
    //helper to be able to have node acess
    void vertsum()
    {
    	map<int, int> m;
    	int hd;
    	vertSum(root, hd, m);
    }
    
    //recursively calls itself down tree adding to a map reference then when it
    //comes back up to root displays sums. helper function because no node acess outside tree
    void vertSum(Node* node,int hd,std::map<int,  int>& m)
    {
    	if(node == nil)
    	{
    		cout << "Part 3" << endl;
    		return;
    	}
    	m[hd] += node->value;
    	if(node->left != nil)
    	{
    		vertSum(node->left, hd - 1, m);
    	}
    	if(node->right != nil)
    	{
    		vertSum(node->right, hd + 1, m);
    	}
    	if(node == root)
    	{
    		cout << "Part 3" << endl;
    		for(auto curr = m.begin(); curr != m.end(); ++curr)
    		{
    			cout << curr->second << ' ';
    		}
    		cout << endl;
    	}
    }
    
    //sets all cover to false
    void makeFalse(Node* n)
    {
    	if(n == nil) return;
        if(n == nil)
        {
            return;
        }
        n->selected = false;
        makeFalse(n->left);
        makeFalse(n->right);
    }
    
    //creates the cover by recursively calling down making every other node true
    // and if it hits leaf it starts back up the node above a leaf is always true to minimize cover.
    bool creatCover(Node* n, bool cover)
    {
    	if(n == nil) return false;
        if(n->left == nil && n->right == nil)
        {
            return n->selected;
        }
        n->selected = !cover;
        if(n->left != nil)
        {
            if(!creatCover(n->left, !cover))
            {
                n->selected = true;
            }
        }
        if(n->right != nil)
        {
            if(!creatCover(n->right, !cover))
            {
                n->selected = true;
            }
        }
        return n->selected;
    }
    
    //uses two helpers to create the cover
    void minCover()
    {
        if(root->left != nil)
        {
            if(root->left->selected == true)
            {
                makeFalse(root);
            }
        }
        creatCover(root, true);
    }
    
    //outputs nodes with true by recursive search numOut is reference so when modified
    //if changes in minCover so that it knows the number of true nodes
    void coverDisplay(Node* n, int& numOut)
    {
    	if(n == nil) return;
        if(n->left != nil)
        {
            coverDisplay(n->left, numOut);
        }
        if(n->selected == true)
        {
            cout << n->value << ' ';
            ++numOut;
        }
        if(n->right != nil)
        {
            coverDisplay(n->right, numOut);
        }
        return;
    }
    
    void displayMinCover()
    {
        int numNodes = 0;
        cout << "Part 1" << endl;
        coverDisplay(root, numNodes);
        cout << endl;
        cout << numNodes << endl;
    }
}; // BST