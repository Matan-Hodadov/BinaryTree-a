#pragma once

#include <Node.hpp>
#include <stack>

namespace ariel
{
    template<typename T>
    class preorder_iterator
    {
        private:
        std::stack<Node<T>* > nodes;

        public:
        preorder_iterator(){};
        preorder_iterator(Node<T>* root)
        {
            this->nodes.push(root);
        };
        
        preorder_iterator<T>& operator ++ ()
        {
            Node<T>* current_node = nodes.top();
            nodes.pop();
            if (current_node->right != nullptr)
            {
                nodes.push(current_node->right);
            }
            if (current_node->left != nullptr)
            {
                nodes.push(current_node->left);
            }
            return *this;
        }
        T& operator * ()
        {
            return nodes.top()->data;
        }
        T* operator -> ()
        {
            return &(nodes.top()->data);
        }
        bool operator != (const preorder_iterator &other) const
        {
            if(this->nodes.empty() && other.nodes.empty())
            {
                return false;
            }
            if(this->nodes.empty() || other.nodes.empty())
            {
                return true;
            }
            if(this->nodes.top() != other.nodes.top())
            {
                return true;
            }
            return false;
        }
        Node<T>* get_node()
        {
            return nodes.top();
        }
    };
};