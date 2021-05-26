#include "doctest.h"
#include "BinaryTree.hpp"

#include <array>
#include <vector>
#include <string>

using namespace std;
using namespace ariel;

template <typename T>
void pre_order(vector<T>& nodes, Node<T>* current_node)
{
    if(current_node != nullptr)
    {
        nodes.push_back(current_node->data);
        pre_order(nodes, current_node->left);
        pre_order(nodes, current_node->right);
    }
}

template <typename T>
void in_order(vector<T>& nodes, Node<T>* current_node)
{
    if(current_node != nullptr)
    {
        in_order(nodes, current_node->left);
        nodes.push_back(current_node->data);
        in_order(nodes, current_node->right);
    }
}

template <typename T>
void post_order(vector<T>& nodes, Node<T>* current_node)
{
    if(current_node != nullptr)
    {
        post_order(nodes, current_node->left);
        post_order(nodes, current_node->right);
        nodes.push_back(current_node->data);
    }
}

TEST_CASE("char tree test - 1 (balanced tree)")
{
    //build the tree
    BinaryTree<char> tree;
    CHECK_NOTHROW(tree.add_root('a'));
    CHECK_NOTHROW(tree.add_left('a', 'b'));
    CHECK_NOTHROW(tree.add_right('a', 'c'));
    CHECK_NOTHROW(tree.add_left('b', 'd'));
    CHECK_NOTHROW(tree.add_right('b', 'e'));
    CHECK_NOTHROW(tree.add_left('c', 'f'));
    CHECK_NOTHROW(tree.add_right('c', 'g'));
    const int num_of_nodes_char_tree = 8;
    size_t index = 0;

    //subcase for each travel order on the tree
    //in order subcase
    SUBCASE("in order")
    {
        array<int, num_of_nodes_char_tree> in_order_expected_values = {'d', 'b', 'e', 'a', 'f', 'c', 'g'};
        index = 0;
        for(auto iter = tree.begin_inorder(); iter != tree.end_inorder(); ++iter, index++)
        {
            CHECK_EQ(in_order_expected_values.at(index) ,*iter);
        }
        CHECK_EQ(index, num_of_nodes_char_tree);
    }

    //pre order subcase
    SUBCASE("pre order")
    {
        array<int, num_of_nodes_char_tree> pre_order_expected_values = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};
        index = 0;
        for(auto iter = tree.begin_preorder(); iter != tree.end_preorder(); ++iter, index++)
        {
            CHECK_EQ(pre_order_expected_values.at(index) ,*iter);
        }
        CHECK_EQ(index, num_of_nodes_char_tree);
    }

    //post order subcase
    SUBCASE("post order")
    {
        array<int, num_of_nodes_char_tree> post_order_expected_values = {'d', 'e', 'b', 'f', 'g', 'c', 'a'};
        index = 0;
        for(auto iter = tree.begin_postorder(); iter != tree.end_postorder(); ++iter, index++)
        {
            CHECK_EQ(post_order_expected_values.at(index) ,*iter);
        }
        CHECK_EQ(index, num_of_nodes_char_tree);
    }
}

TEST_CASE("char tree test - 2 (unbalanced tree)")
{

    // sdsd
    //build the tree
    BinaryTree<char> tree;
    CHECK_NOTHROW(tree.add_root('x'));
    CHECK_NOTHROW(tree.add_left('x', 'y'));
    CHECK_NOTHROW(tree.add_right('x', 'z'));
    CHECK_NOTHROW(tree.add_left('y', 'k'));
    CHECK_NOTHROW(tree.add_right('k', 't'));
    CHECK_NOTHROW(tree.add_right('z', 'l'));
    const int num_of_nodes_char_tree = 6;
    size_t index = 0;

    //subcase for each travel order on the tree
    //in order subcase
    SUBCASE("in order")
    {
        array<int, num_of_nodes_char_tree> in_order_expected_values = {'d', 'b', 'e', 'a', 'f', 'c', 'g'};
        index = 0;
        for(auto iter = tree.begin_inorder(); iter != tree.end_inorder(); ++iter, index++)
        {
            CHECK_EQ(in_order_expected_values.at(index) ,*iter);
        }
        CHECK_EQ(index, num_of_nodes_char_tree);
    }

    //pre order subcase
    SUBCASE("pre order")
    {
        array<int, num_of_nodes_char_tree> pre_order_expected_values = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};
        index = 0;
        for(auto iter = tree.begin_preorder(); iter != tree.end_preorder(); ++iter, index++)
        {
            CHECK_EQ(pre_order_expected_values.at(index) ,*iter);
        }
        CHECK_EQ(index, num_of_nodes_char_tree);
    }

    //post order subcase
    SUBCASE("post order")
    {
        array<int, num_of_nodes_char_tree> post_order_expected_values = {'d', 'e', 'b', 'f', 'g', 'c', 'a'};
        index = 0;
        for(auto iter = tree.begin_postorder(); iter != tree.end_postorder(); ++iter, index++)
        {
            CHECK_EQ(post_order_expected_values.at(index) ,*iter);
        }
        CHECK_EQ(index, num_of_nodes_char_tree);
    }
}
