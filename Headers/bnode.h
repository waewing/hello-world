#ifndef BNODE_H
#define BNODE_H
#include <iostream>
#include <string>
namespace ds
{

template <class T>
class BNode
{
private:
    BNode<T>* left;
    BNode<T>* right;
    T data;
    // bool leaf;
public:
    BNode() : BNode(NULL,NULL) {}
    
    BNode(BNode<T>* left, BNode<T>* right)
    {
        this->left = left;
        this->right = right;
    }

    BNode<T>* GetLeft() {return left;}
    
    const BNode<T>* GetLeft() const {return left;}
    
    BNode<T>* GetRight() {return right;}
    
    const BNode<T>* GetRight() const {return right;}

    void SetLeft(const BNode<T>* left)
    {
        this->left = left;
    }

    void SetRight(const BNode<T>* right)
    {
        this->right = right;
    }
 
    T& GetData()
    {
        return data;
    }

    void SetData(const T& data)
    {
        this -> data = data;
    }

    BNode<T>* Copy(BNode<T>* root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        BNode<T>* tmp = new BNode<T>(root->GetData());
        tmp->SetLeft(Copy(root->GetLeft()));
        tmp->SetRight(Copy(root->GetRight()));
        return tmp;
    }

    void Clear(BNode<T>*& root)
    {
        if(root != NULL)
        {
            Clear(root->GetLeft());
            Clear(root->GetRight());
            delete root;
            root = NULL;  
        }
    }

    void infix(BNode<T>* root)
    {
        if(root != NULL)
        {
            infix(root->GetLeft());
            std::cout << root->GetData();
            infix(root->GetRight());
        }
    }

    void prefix(BNode<T>* root)
    {
        if(root != NULL)
        {
            std::cout << root->GetData();
            infix(root->GetLeft());
            infix(root->GetRight());
        }
    }

    void postfix(BNode<T>* root)
    {
        if(root != NULL)
        {
            infix(root->GetLeft());
            infix(root->GetRight());
            std::cout << root->GetData();
        }
    }

    bool IsLeaf() const {return ((left == NULL) && (right == NULL));}

    void Insert(BNode<T>*& root, T value)
    {
        if(root == NULL)
        {
            root = new BNode<T>(value);
        }
        else if(root->GetData() <= value)
        {
            Insert(root->GetRight(),value);
        }
        else if(root->GetData() > value)
        {
            Insert(root->GetLeft(),value);
        }
    }


    std::string ToString() const
		{
			std::stringstream out;
			out << data;
			return out.str();
		}

    friend std::ostream& operator<<(std::ostream& out,const BNode<T>& obj)
		{
			out << obj.ToString();
			return out;
		}


}
};


#endif