/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:40:12 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/27 18:22:48 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <functional>
# include <memory>

namespace ft
{

/* ************************************************************************** */
/*                                  NODE CLASS                                */
/* ************************************************************************** */

    template <class T>
    class Node
    {
    private:
    // MEMBER TYPES
        typedef T                   value_type;
        typedef Node <value_type>*  node_ptr

    // ATTRIBUTES
        value_type  data;
        node_ptr    left;
        node_ptr    right;
        node_ptr    parent;
        bool        color;

    public:
    // CONSTRUCTORS / DESTRUCTORS
        Node(value_type data)
        {
            this->data      = data;
            this->left      = NULL;
            this->right     = NULL;
            this->parent    = NULL;
            this->color     = BLACK;
        Node *getRoot(void)
        {return _root;}

    // MEMBER FUNCTIONS
        Node *searchNode(key_type key)
        }
        ~Node(void){}
    };

/* ************************************************************************** */
/*                           RED BLACK TREE CLASS                             */
/* ************************************************************************** */

    template <class T,
            class Compare,
            class Allocator = std::allocator<T>>
    class RedBlackTree
    {
    private:
    // MEMBER TYPES
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

    // ATTRIBUTES
        Node*           _root;
        size_type       _size;
        node_alloc_type _alloc;
        comp_type       _comp;
        
    public:
    // CONSTRUCTORS / DESTRUCTORS
        RedBlackTree()
        {}
        
    // GETTERS
        Node *getRoot(void)
        {return _root;}

    // MEMBER FUNCTIONS
        Node *searchNode(key_type key)
        {
            Node *node = _root;
            while (node != null) 
            {
                if (key == node->data.first)
                    return node;
                else if (_comp(key, node->data.first))
                    node = node.left;
                else
                    node = node.right;
            }
            return null;
        }

        void insertNode(const value_type& x)
        {
            Node    *newNode(x);
            Node    *currentNode;

            if (!_root)
            {
                _root = newNode;
                return;
            }
            currentNode = _root;
            while (true)
            {
                if (newNode->data.first == currentNode->data.first)
                    currentNode->data.second = newNode->data.second;
                else if (_comp(newNode->data.first, currentNode->data.first))
                {
                    if (currentNode->left)
                        currentNode = currentNode->left;
                    else
                    {
                        currentNode->left = newNode;
                        newNode->parent = currentNode;
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
                        return;
                    }
                }
// ########### Et ici si pas de creation de nouveau noeud, pas besoin de detruire celui cree
// ########### car sera de toute facon detruit a la fin de la fonction ?
            }
        }
    };
}

#endif