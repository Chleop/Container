/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:40:12 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/28 19:22:37 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <functional>
# include <memory>

# define BLACK  0
# define RED    1

namespace ft
{

/* ************************************************************************** */
/*                                  NODE CLASS                                */
/* ************************************************************************** */

template <class T>
class Node
{
public:
// MEMBER TYPES
    typedef T                   value_type;
    typedef Node <value_type>*  node_ptr;

// ATTRIBUTES
    value_type  data;
    node_ptr    left;
    node_ptr    right;
    node_ptr    parent;
    bool        color;

// CONSTRUCTORS / DESTRUCTORS
    Node(value_type data)
    {
        this->data      = data;
        this->left      = NULL;
        this->right     = NULL;
        this->parent    = NULL;
        this->color     = RED;
    }
    ~Node(void){}
};

/* ************************************************************************** */
/*                           RED BLACK TREE CLASS                             */
/* ************************************************************************** */

template <class T,
        class Compare = std::less<T>,
        class Allocator = std::allocator<T>>
class RedBlackTree
{
public:
/* ************************************************************************** */
/*                               MEMBER TYPES                                 */
/* ************************************************************************** */
    typedef T                   value_type;
    typedef ft::Node<T>         node_type;
    typedef value_type*         pointer;
    typedef const value_type*   const_pointer;
    typedef value_type&         reference;
    typedef const value_type&   const_reference;
    typedef size_t              size_type;
    typedef ptrdiff_t           difference_type;
    typedef typename Allocator::template rebind<value_type>::other  node_alloc_type;
    typedef Compare             comp_type;
    typedef Node<value_type>*   node_ptr;

private:
/* ************************************************************************** */
/*                              MY SECRET GARDEN                              */
/* ************************************************************************** */

    node_ptr        _root;
    size_type       _size;
    node_alloc_type _alloc;
    comp_type       _comp;
    
public:
/* ************************************************************************** */
/*                        CONSTRUCTORS / DESTRUCTORS                          */
/* ************************************************************************** */

    RedBlackTree(const comp_type& cmp = comp_type(), const node_alloc_type& a = node_alloc_type()):
    _root(NULL), _size(0), _alloc(a), _comp(cmp)
    {}

    ~RedBlackTree(void){}
    
/* ************************************************************************** */
/*                                  GETTERS                                   */
/* ************************************************************************** */

    node_ptr getRoot(void)
    {return _root;}

/* ************************************************************************** */
/*                                  CAPACITY                                  */
/* ************************************************************************** */

    size_type size()
    {return _size;}

/* ************************************************************************** */
/*                               ELEMENTS ACCESS                              */
/* ************************************************************************** */

    node_ptr parent(node_ptr n)
    {if (n)
        return n->parent;
    return NULL;}

    node_ptr grandparent(node_ptr n)
    {return parent(parent(n));}

    node_ptr sister(node_ptr n)
    {node_ptr p = parent(n);
    if (!p)
        return NULL;
    if (n == p->left)
        return p->right;
    return p->left;}

    node_ptr aunt(node_ptr n)
    {node_ptr p = parent(n);
    return sister(p);}

    node_ptr searchNode(const value_type& x)
    {
// remettre la comparaison avec data.first pour les pairs
        node_ptr node = _root;

        while (node)
        {
            if (x == node->data)
                return node;
            else if (_comp(x, node->data))
                node = node->left;
            else
                node = node->right;
        }
        return NULL;
    }

/* ************************************************************************** */
/*                                  MODIFIERS                                 */
/* ************************************************************************** */

    void rotateLeft(node_ptr n)
    {
        node_ptr y = n->right;

        n->right = y->left;
        if (y->left)
            y->left->parent = n;
        y->parent = n->parent;
        if (n->parent == NULL)
            n = y;
        else if (n == n->parent->left)
            n->parent->left = y;
        else
            n->parent->right = y;
        y->left = n;
        n->parent = y;
    }

    void rotateRight(node_ptr n)
    {
        node_ptr y = n->left;

        n->left = y->right;
        if (y->right)
            y->right->parent = n;
        y->parent = n->parent;
        if (n->parent == NULL)
            n = y;
        else if (n == n->parent->right)
            n->parent->right = y;
        else
            n->parent->left = y;
        y->right = n;
        n->parent = y;
    }

    void insertNaively(node_ptr newNode, node_ptr currentNode)
    {
        if (!_root)
        {
            _root = newNode;
            _size++;
            return;
        }
        currentNode = _root;
        while (true)
        {
            // remettre la comparaison avec data.first pour les pairs
            if (newNode->data == currentNode->data)     // ici .first
                currentNode->data = newNode->data;      // ici .second
            else if (_comp(newNode->data, currentNode->data))
            {
                if (currentNode->left)
                    currentNode = currentNode->left;
                else
                {
                    currentNode->left = newNode;
                    newNode->parent = currentNode;
                    _size++;
                    return;
                }
            }
            else
            {
                if (currentNode->right)
                    currentNode = currentNode->right;
                else
                {
                    currentNode->right = newNode;
                    newNode->parent = currentNode;
                    _size++;
                    return;
                }
            }
// ########### Et ici si pas de creation de nouveau noeud, pas besoin de detruire celui cree
// ########### car sera de toute facon detruit a la fin de la fonction ?
        }
    }

    void reequilibrateTree(node_ptr n)
    {
        node_ptr myparent = parent(n);

        // Case 1: Parent is NULL, we've reached the root, the end of the recursion
        // Case 2: Parent is black --> nothing to do
        if ((myparent == NULL) || (myparent->color == BLACK))
            return;

        node_ptr mygrandparent = grandparent(n);

        // Case 3:
        // Not having a grandparent means that parent is the root.
        // As this method is only called on red nodes (either on newly inserted ones - or -
        // recursively on red grandparents), all we have to do is to recolor the root black.
        if (mygrandparent == NULL) 
        {
            myparent->color = BLACK;
            return;
        }

        // Get the aunt (may be NULL/nil, in which case its color is BLACK)
        // then recursively for grandparent.
        node_ptr myaunt = aunt(n);

        // Case 3: aunt is red -> recolor parent, grandparent and aunt
        if (myaunt != NULL && myaunt->color == RED)
        {
            myaunt->color = BLACK;
            myparent->color = BLACK;
            mygrandparent->color = RED;
            reequilibrateTree(mygrandparent);
        }
        // Case 4: Parent is left child of grandparent
        else if (myparent == mygrandparent->left)
        {
        // Aunt is black and node is left->right "inner child" of its grandparent
        // Let "parent" point to the new root node of the rotated sub-tree.
        // It will be recolored in the next step.
            if (n == myparent->right)
            {
                rotateLeft(myparent);
                myparent = n;
            }
        // Aunt is black and node is left->left "outer child" of its grandparent
            rotateRight(mygrandparent);
        // Recolor original parent and grandparent
            myparent->color = BLACK;
            mygrandparent->color = RED;
        }
        // Case 5: Parent is right child of grandparent
        else
        {
        // Aunt is black and node is right->left "inner child" of its grandparent
        // Let "parent" point to the new root node of the rotated sub-tree.
        // It will be recolored in the next step.
            if (n == myparent->left)
            {
                rotateRight(myparent);
                myparent = n;
            }
        // Aunt is black and node is right->right "outer child" of its grandparent
            rotateLeft(mygrandparent);
        // Recolor original parent and grandparent
            myparent->color = BLACK;
            mygrandparent->color = RED;
        }
    }

    void insertNode(const value_type& x)
    {
        // node_type   node(x);
        // node_ptr    newNode = &node;
        node_ptr newNode = new Node<int>(x);
        node_ptr    currentNode;

        if (!_root)
        {
            _root = newNode;
            _size++;
            return;
        }
        insertNaively(newNode, currentNode);
        if (newNode->data != currentNode->data)  // ici .first
            reequilibrateTree(newNode);
        return;
    }

/* ************************************************************************** */
/*                              PRINT FUNCTIONS                               */
/* ************************************************************************** */

    void    printNode(node_ptr node)
    {
        std::cout << "Node data   : " << node->data << std::endl;
        std::cout << "Node left   : " << node->left << std::endl;
        std::cout << "Node right  : " << node->right << std::endl;
        std::cout << "Node parent : " << node->parent << std::endl;
        std::cout << "Node color  : " << node->color << std::endl;
    }

    void visualize(node_ptr node, std::string indent, bool right)
    {
        if (node == _root)
            std::cout << "Size of RBT is : " << size() << std::endl;
        if (node != NULL){
            std::cout << indent;
            if (right)
            {
                std::cout << "R----";
                indent += "     ";
            }
            else
            { 
                if (node != _root)
                {
                    std::cout << "L----";
                    indent += "|    ";
                }
            }
            std::cout << node->data << "(" << (node->color ? "RED" : "BLACK") << ")" << std::endl;
            
            visualize(node->left, indent, false);
            visualize(node->right, indent, true);
        }
    }

    void visualize(void)
    {
        visualize(_root, "", false);
    }

};
}

#endif