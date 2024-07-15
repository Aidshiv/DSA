def negate_literal(literal):
""" Negate a literal by adding or removing the negation symbol '~' """
if literal.startswith('~'):
return literal[1:] # Remove negation
else:
return '~' + literal # Add negation
def resolve(clause1, clause2):
""" Resolve two clauses to derive a new clause """
new_clause = []
resolved = False
# Copy literals from both clauses
for literal in clause1:
if negate_literal(literal) in clause2:
resolved = True
else:
new_clause.append(literal)
for literal in clause2:
if negate_literal(literal) not in clause1:
new_clause.append(literal)
if resolved:
return new_clause
else:
return None # No resolution possible
def resolution(propositional_kb, query):
""" Use resolution to prove or disprove a query using propositional logic """
kb = propositional_kb[:]
kb.append(negate_literal(query)) # Add negated query to knowledge base
while True:
new_clauses = []
n = len(kb)
resolved_pairs = set() # Track resolved pairs to avoid redundant resolutions
for i in range(n):
for j in range(i + 1, n):
clause1 = kb[i]
clause2 = kb[j]
if (clause1, clause2) not in resolved_pairs:
resolved_pairs.add((clause1, clause2))
resolvent = resolve(clause1, clause2)
if resolvent is None:
continue # No resolution possible for these clauses
if len(resolvent) == 0:
return True # Empty clause (contradiction), query is proved
if resolvent not in new_clauses:
new_clauses.append(resolvent)
if all(clause in kb for clause in new_clauses):
return False # No new clauses added, query cannot be proven
kb.extend(new_clauses) # Add new clauses to the knowledge base
# Example propositional knowledge base (list of clauses)
propositional_kb = [
['~P', 'Q'],
['P', '~Q', 'R'],
['~R', 'S']
]
# Example query to prove/disprove using resolution
query = 'S'
# Use resolution to prove or disprove the query
result = resolution(propositional_kb, query)
if result:
print(f"The query '{query}' is PROVED.")
else:
print(f"The query '{query}' is DISPROVED.")