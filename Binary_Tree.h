/*
 Module: Binary_Tree.h
 Date: 21-11-2022
 Author: Yashkumar Patel
*/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

/** Class for a binary tree. */

#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "BTNode.h"

template<typename Item_Type>
  class Binary_Tree
{
  public:

  // Constructors and Functions

  /** Construct an empty Binary_Tree. */
Binary_Tree() : root(NULL) {}

  /** Construct a Binary_Tree with two subtrees.
      @param the_data The data at the root
      @param left_child The left subtree
      @param right_child The right subtree
  */
Binary_Tree(const Item_Type& the_data, 
            const Binary_Tree<Item_Type>& left_child
              = Binary_Tree(),
            const Binary_Tree<Item_Type>& right_child
               = Binary_Tree()):
  root(new BTNode<Item_Type>(the_data, left_child.root,
                             right_child.root)) {}

  /** Virtual destructor to avoid warnings */
  virtual ~Binary_Tree() {} // Do nothing.

  Item_Type getdata() { return root->data; }
  /** Return the left subtree. */
  Binary_Tree<Item_Type>& get_left_subtree() const;

  /** Return the right subtree. */
  Binary_Tree<Item_Type>& get_right_subtree() const;

  /** Return the data field of the root.
      @throws std::invalid_argument if empty tree
  */
  const Item_Type& get_data() const;

  /** Indicate that this is the empty tree. */
  bool is_null() const;

  /** Indicate that this tree is a leaf. */
  bool is_leaf() const;

  /** Return a string representation of this tree. */
  virtual std::string to_string() const;
  
  /* insert a item in tree according to given code*/
  void setroot(const Item_Type &target);
  
  /** Read a binary tree */
  static Binary_Tree<Item_Type> read_binary_tree(std::istream& in);

  /* = operator overloaded for the sake of assignment*/
   void operator=(Binary_Tree<Item_Type>& RHS);
  
  /** Return a string representation of the root */
  std::string root_to_string() const {
    return root->to_string();
  }


  protected:

  // Protected constructor
  /** Construct a Binary_Tree with a given node as the root */
Binary_Tree(BTNode<Item_Type>* new_root) : root(new_root) {}

  // Data Field
  BTNode<Item_Type>* root;

 private:

 
};  // End Binary_Tree

// Overloading the ostream insertion operator.
template<typename Item_Type>
  std::ostream& operator<<(std::ostream& out, 
                           const Binary_Tree<Item_Type>& tree)
{
  return out << tree.to_string();
}

// Overloading the istream extraction operator
template<typename Item_Type>
  std::istream& operator>>(std::istream& in, 
                           Binary_Tree<Item_Type>& tree)
{
  tree = Binary_Tree<Item_Type>::read_binary_tree(in);
  return in;
}

// Implementation of member functions

/** Return a string representation of this tree */
template<typename Item_Type>
std::string Binary_Tree<Item_Type>::to_string() const {
  std::ostringstream os;
  if (is_null())
    os << "NULL\n";
  else {
    os << *root << '\n';
    os << get_left_subtree().to_string();
    os << get_right_subtree().to_string();
  }
  return os.str();
}
template<typename Item_Type>
  Binary_Tree<Item_Type> Binary_Tree<Item_Type>::
    read_binary_tree(std::istream& in) {
  std::string next_line;
  getline(in, next_line);
  if (next_line == "NULL") {
    return Binary_Tree<Item_Type>();
  } else {
    Item_Type the_data;
    std::istringstream ins(next_line);
    ins >> the_data;
    Binary_Tree<Item_Type> left = read_binary_tree(in);
    Binary_Tree<Item_Type> right = read_binary_tree(in);
    return Binary_Tree<Item_Type>(the_data, left, right);
  }
}
  template<typename Item_Type>
  const Item_Type& Binary_Tree<Item_Type>::get_data() const
  {
      if (root!=NULL)
      {

          return root->data;
      }
      else
      {
          return -1;
      }
  }
  template<typename Item_Type>
  bool Binary_Tree<Item_Type>::is_null() const
  {
      if (root==NULL)
      {
          return true;
      }
      else
      {
          return false;
      }
  }
  template<typename Item_Type>
  bool Binary_Tree<Item_Type>::is_leaf() const
  {
      if (root->left==NULL&&root->right==NULL)
      {
          return true;
      }
      else
      {
          return false;
      }
  }

  template<typename Item_Type>
  Binary_Tree<Item_Type>& Binary_Tree<Item_Type>:: get_left_subtree() const
  {
      Binary_Tree<Item_Type> tree;
      if (root->left==NULL)
      {
          root->left = new BTNode<Item_Type>(' ');
      }
      tree.root = root->left;
      return tree;
  }

  template<typename Item_Type>
  Binary_Tree<Item_Type>& Binary_Tree<Item_Type>::get_right_subtree() const
  {
      Binary_Tree<Item_Type> tree;
      if (root->right == NULL)
      {
          root->right = new BTNode<Item_Type>(' ');
      }
      tree.root = root->right;
      return tree;
  }
  template<typename Item_Type>
  void Binary_Tree<Item_Type>::setroot(const Item_Type& target)
  {
      if (root == NULL)
      {
          root = new BTNode<Item_Type>(target);
          root->data = target;
      }
      else
      {
                root->data = target;
      }

  }
  template<typename Item_Type>
  void Binary_Tree<Item_Type>::operator=(Binary_Tree<Item_Type> &RHS)
  {
      root = RHS.root;
  }
#endif

