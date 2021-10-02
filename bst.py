from __future__ import annotations
from typing import Optional
from dataclasses import dataclass
from collections import deque

@dataclass
class BSTNode:
    val: int
    count: int = 1
    left: Optional[BSTNode] = None
    right: Optional[BSTNode] = None

    def __repr__(self):
        return '[{},  left: {}, right: {}]'.format(
                self.val,
                self.left,
                self.right
        )


@dataclass
class BST:
    root: Optional[TreeNode] = None

    def is_empty() -> bool:
        return self.root is None
    
    def _insert(self, node: Optional[BSTNode], key: int) -> BSTNode:
        if node is None:
            return BSTNode(key)
        
        if node.val == key:
            node.count += 1
        elif key < node.val:
            node.left = self._insert(node.left, key)
        else:
            node.right = self._insert(node.right, key)
        return node

    def insert(self, key: int) -> None:
        self.root = self._insert(self.root, key)

    def _remove(self, node: BSTNode, key: int) -> Optional[BSTNode]:
        if node.val == key:
            if node.count > 1:
                node.count -= 1
            if node.count == 1:
                if not node.left and not node.right:
                    return None
                elif not node.left or not node.right:
                    return node.right or node.left
                else:
                    if not node.right.left:
                        node.val, node.count = node.right.val, node.right.count
                        node.right = node.right.right
                    else:
                        pre, succ = node.right, node.right.left
                        while succ.left:
                            pre, succ = succ, succ.left

                        node.val, node.count = node.right.val, node.right.count
                        pre.left = None
            else:
                raise Exception('invariant not held')
        elif key < node.val:
            node.left = self._remove(node.left, key)
        else:
            node.right = self._remove(node.right, key)
        return node

    def remove(self, key: int) -> None:
        self.root = self._remove(self.root, key)

    def _find(self, node: Optional[BSTNode], key: int) -> Optional[BSTNode]:
        if node is None:
            return None

        if node.val == key:
            return node
        elif key < node.val:
            return _find(node.left, key)
        else:
            return _find(node.right, key)

    def find(self, key: int) -> Optional[BSTNode]:
        return self._find(self.root, key)

    def _upper_bound(self, node: Optional[BSTNode], key: int) -> Optional[BSTNode]:
        if not node:
            return None
        
        if node.val > key and node.left:
            return self._upper_bound(node.left, key)
        elif node.val <= key and node.right:
            return self._upper_bound(node.right, key)
        return node

    def upper_bound(self, key: int) -> Optional[BSTNode]:
        return self._upper_bound(self.root, key)

    def _lower_bound(self, node: Optional[BSTNode], key: int) -> Optional[BSTNode]:
        if not node:
            return None

        if node.val >= key and node.left:
            return self._lower_bound(node.left, key)
        elif node.val < key and node.right:
            return self._lower_bound(node.right, key)
        return node

    def lower_bound(self, key: int) -> Optional[BSTNode]:
        return self._lower_bound(self.root, key)

    def min_node(self) -> BSTNode:
        node = self.root

        while node and node.left:
            node = node.left

        return node

    def bfs(self, fun) -> None:
        queue = deque([self.root])
        
        while queue:
            node = queue.popleft()

            if not node:
                continue

            fun(node)
            queue.append(node.left)
            queue.append(node.right)

    def preorder(self, fun) -> None:
        stack = [self.root]
        while stack:
            node = stack.pop()

            if not node:
                continue

            fun(node)
            stack.append(node.left)
            stack.append(node.right)

    def inorder(self, fun) -> None:
        stack = [(False, self.root)]
        while stack:
            visiting, node = stack.pop()

            if not node:
                continue

            if visiting:
                fun(node)
            else:
                stack.append((False, node.right))
                stack.append((True, node))
                stack.append((False, node.left))

    def postorder(self, fun) -> None:
        stack = [(False, self.root)]
        while stack:
            visiting, node = stack.pop()

            if not node:
                continue

            if visiting:
                fun(node)
            else:
                stack.append((False, node.right))
                stack.append((False, node.left))
                stack.append((True, node))

    def layers(self) -> list[list[BSTNode]]:
        result = []

        layer, next_layer = deque([self.root]), deque()
        while layer:
            result_layer = list(filter(None, layer))
            if result_layer:
                result.append(result_layer)

            for node in layer:
                if not node: continue
                next_layer.append(node.left)
                next_layer.append(node.right)

            layer = next_layer
            next_layer = deque()

        return result

