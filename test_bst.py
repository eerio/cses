from bst import BST

tree = BST()

#   100
# 50  200
#    175 225
for x in [100, 50, 200, 175, 225]:
    tree.insert(x)

val_layers = [[node.val for node in layer] for layer in tree.layers()]
assert val_layers == [[100], [50, 200], [175, 225]]

#                100
#          50          200
#    -100     75     175   225
# -200   0
for x in [-100, -200, 0, 75]:
    tree.insert(x)

#                100
#          75          200
#    -100           175   225
# -200
for x in [0, 50]:
    tree.remove(x)


print(tree.layers())
print(tree.root)
