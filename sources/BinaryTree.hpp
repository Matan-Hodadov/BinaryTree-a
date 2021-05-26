#pragma once

#include <iostream>

#include <vector>
#include "Node.hpp"

#include "InOrderIterator.hpp"
#include "PreOrderIterator.hpp"
#include "PostOrderIterator.hpp"

namespace ariel
{
    template <typename T>
    class BinaryTree
    {
        private:
        Node<T>* root;
        Node<T>* find_value(T value)
        {
            for(auto iter = begin_preorder(); iter != end_preorder(); ++iter)
            {
                if(*iter == value)
                {
                    return iter.get_node();
                }
            }
            throw std::invalid_argument("there is no node with the parent value");
        }

        public:
        BinaryTree()
        {
            this->root = nullptr;
        }
        ~BinaryTree()
        {
            if(this->root == nullptr)
            {
                return;
            }
            for (auto iter = begin_preorder(); iter != end_preorder();)
            {
                Node<T> *current_node = iter.get_node();
                ++iter;
                delete current_node;
            }
        }

        BinaryTree& add_root(T value)
        {
            if(this->root == nullptr)
            {
                this->root = new Node<T>();
                this->root->data = value;
            }
            return (*this);
        } 

        BinaryTree& add_left(T parent_value, T left_child_value)
        {
            Node<T>* parent_node = this->find_value(parent_value);
            if(parent_node->left == nullptr)
            {
                parent_node->left = new Node<T>();
                parent_node->left->data = left_child_value;
            }
            else
            {
                parent_node->left->data = left_child_value;
            }
            return (*this);
        }

        BinaryTree& add_right(T parent_value, T right_child_value)
        {
            Node<T>* parent_node = this->find_value(parent_value);
            if(parent_node->right == nullptr)
            {
                parent_node->right = new Node<T>();
                parent_node->right->data = right_child_value;
            }
            else
            {
                parent_node->right->data = right_child_value;
            }
            return (*this);
        } 
        
        preorder_iterator<T> begin_preorder() {return preorder_iterator<T>{root};}
        preorder_iterator<T> end_preorder() {return preorder_iterator<T>{};}

        inorder_iterator<T> begin_inorder() {return inorder_iterator<T>{root};}
        inorder_iterator<T> end_inorder() {return inorder_iterator<T>{};}

        postorder_iterator<T> begin_postorder() {return postorder_iterator<T>{root};}
        postorder_iterator<T> end_postorder() {return postorder_iterator<T>{};}

        inorder_iterator<T> begin() {return inorder_iterator<T>{root};}
        inorder_iterator<T> end() {return inorder_iterator<T>{};}

        friend std::ostream& operator << (std::ostream& os, const BinaryTree<T>& tree);

        //tests' heling function
        Node<T>* get_root()
        {
            if(this->root != nullptr)
            {
                return this->root;
            }
            throw std::invalid_argument("there is no root");
        }
    };

    //the operator << friend function
    template <typename T>
    std::ostream& operator << (std::ostream& os, BinaryTree<T>& tree)
    {
        os << "\nthe values of each node in the tree are:" << std::endl;
        for (auto element : tree)
        {
            os << element << " ";
        }
        os << std::endl;
        return os;
    }
};