#functions.py
import sys
import os
from dataclasses import dataclass

class NFA:
    states = None
    alphabet = None
    start_state = None
    final_states = None
    transitions = None

def read_nfa(nfa_file):
    my_file = open(nfa_file)
    my_file = my_file.readlines()
    d_nfa = dict()

    states = my_file[0].split()
    alphabet = my_file[1].strip().split()
    start_state = my_file[2].strip()
    final_states = set(my_file[3].strip().split())
    my_file[0] = my_file[0].split()


    # initialize each state for each member of the alphabet
    for state in states:
        d_nfa[state] = dict()
        d_nfa[state]['&'] = []

        for letter in alphabet:
            d_nfa[state][letter] = []
    #add transitions
    for line in my_file[4:]:
        line = line.split()
        curr = line[0]
        value = line[1]
        new = line[2]

        if new not in set(d_nfa[curr][value]):
            d_nfa[curr][value].append(new)

    #create the nfa
    nfa = NFA()
    nfa.states = states
    nfa.alphabet = alphabet
    nfa.start_state = start_state
    nfa.final_states = final_states
    nfa.transitions = d_nfa
    return nfa

def print_file(the_file):
    f = open(the_file, "r")
    check = False
    
    for line in f:
        print(line, end='')

    f.close()

    os.remove(the_file)


def string_nfa(w, output_file):
    #w = list(sys.argv[1:][0])

    f = open(output_file, "w")
    if not w:
        #epsilon case:
        f.write("0\n\n0\n0\n")
    else:
        states = "0"
        alphabet = ""
        size = len(w)
        for i, letter in enumerate(w, 1):
            states = states + " " + str(i)

            if i == 1:
                alphabet = alphabet + letter
            else:
                alphabet = alphabet + " " + letter
            #print(letter, end='')
        final_state = str(size)

        f.write(states)
        f.write('\n')

        f.write(alphabet)
        f.write('\n')

        f.write("0")
        f.write('\n')

        f.write(final_state)
        f.write('\n')

        states = states.split()
        alphabet = alphabet.split()

        for i, state in enumerate(states):
            if i < size:
                line = ""
                line = line + states[i] + " " + alphabet[i] + " " + states[i+1]
                f.write(line)
                f.write('\n')

    f.close()

def union_nfa(nfa_file1, nfa_file2, output_file):
    
    f = open(output_file, "w")
    
    M1 = read_nfa(nfa_file1)
    M2 = read_nfa(nfa_file2)

    M1_size = len(M1.states)
    M2_size = len(M2.states)

    size = M1_size + M2_size
    alphabet_set = set()

    alphabet = ""
    states = "0"
    start_state = "0"
    final_states = ""

    for enum, letter in enumerate(M1.alphabet):
        if letter not in alphabet_set:
            alphabet_set.add(letter)
            if not enum:
                alphabet = alphabet + letter
            else:
                alphabet = alphabet + ' ' + letter

    for letter in M2.alphabet:
        if letter not in alphabet_set:
            alphabet_set.add(letter)
            alphabet = alphabet + ' ' + letter

    for i in range(1, size+1):
        states = states + " " + str(i)

    f.write(states)
    f.write('\n')

    f.write(alphabet)
    f.write('\n')

    f.write(start_state)
    f.write('\n')

    states = states.split()

    M1_to_M = {}
    M2_to_M = {}
    i = 1

    for enum, state in enumerate(M1.states):
        M1_to_M[state] = states[i]

        if state in M1.final_states:
            if not final_states:
                final_states = states[i]
            else:
                final_states = final_states + " " + states[i]
        i = i + 1
    for state in M2.states:
        M2_to_M[state] = states[i]

        if state in M2.final_states:
            final_states = final_states + " " + states[i]
        i = i + 1

    f.write(final_states)
    f.write('\n')

    f.write(f"0 & {M1_to_M[M1.start_state]}")
    f.write('\n')

    f.write(f"0 & {M2_to_M[M2.start_state]}")
    f.write('\n')


    M1.alphabet.append('&')
    for state in M1.states:
        for value in M1.alphabet:
            transitions = M1.transitions[state][value]
            if transitions is not None:
                for transition in transitions:
                    f.write(f'{M1_to_M[state]} {value} {M1_to_M[transition]}')
                    f.write('\n')

    M2.alphabet.append('&')
    for state in M2.states:
        for value in M2.alphabet:
            transitions = M2.transitions[state][value]
            if transitions is not None:
                for transition in transitions:
                    f.write(f'{M2_to_M[state]} {value} {M2_to_M[transition]}')
                    f.write('\n')

    f.close()

def concat_nfa(nfa_file1, nfa_file2, output_file):
    
    f = open(output_file, "w")

    M1 = read_nfa(nfa_file1)
    M2 = read_nfa(nfa_file2)
    size = len(M1.states) + len(M2.states)

    states = ""
    alphabet = ""

    alphabet_set = set()
    for i in range(0, size):
        if not i:
            states = str(i)
        else:
            states = states + " " + str(i)

    for enum, letter in enumerate(M1.alphabet):
        if letter not in alphabet_set:
            alphabet_set.add(letter)
            if not enum:
                alphabet = alphabet + letter
            else:
                alphabet = alphabet + ' ' + letter

    for letter in M2.alphabet:
        if letter not in alphabet_set:
            alphabet_set.add(letter)
            alphabet = alphabet + ' ' + letter

    #print states, alphabet, and start state
    f.write(states)
    f.write('\n')

    f.write(alphabet)
    f.write('\n')

    states = states.split()
    f.write(states[0])
    f.write('\n')


    final_states = ""

    M1_to_M = {}
    M2_to_M = {}
    i = 0

    for state in M1.states:
        M1_to_M[state] = states[i]
        i = i + 1

    marker = i

    for state in M2.states:
        M2_to_M[state] = states[i]

        if state in M2.final_states:
            if not final_states:
                final_states = final_states + states[i]
            else:
                final_states = final_states + " " + states[i]
        i = i + 1

    #print final states
    f.write(final_states)
    f.write('\n')

    M1.alphabet.append('&')
    for state in M1.states:
        for value in M1.alphabet:
            transitions = M1.transitions[state][value]
            if transitions is not None:
                for transition in transitions:
                    f.write(f'{M1_to_M[state]} {value} {M1_to_M[transition]}')
                    f.write('\n')

    for state in M1.final_states:
        f.write(f"{M1_to_M[state]} & {states[marker]}")
        f.write('\n')


    M2.alphabet.append('&')
    for state in M2.states:
        for value in M2.alphabet:
            transitions = M2.transitions[state][value]
            if transitions is not None:
                for transition in transitions:
                    f.write(f'{M2_to_M[state]} {value} {M2_to_M[transition]}')
                    f.write('\n')

    f.close()


def star_nfa(nfa_file1, output_file):

    M1 = read_nfa(nfa_file1)
    f = open(output_file, "w")


    alphabet = ""
    states = "0"

    for enum, letter in enumerate(M1.alphabet):
        if not enum:
            alphabet = alphabet + letter
        else:
            alphabet = alphabet + ' ' + letter


    for i in range(1, len(M1.states) + 1):
        states = states + " " + str(i)

    f.write(states)
    f.write('\n')

    f.write(alphabet)
    f.write('\n')

    f.write("0")
    f.write('\n')


    states = states.split()

    final_states = ""
    M1_to_M = {}
    i = 1

    for enum, state in enumerate(M1.states):
        M1_to_M[state] = states[i]

        if state in M1.final_states:
            if not final_states:
                final_states = states[i]
            else:
                final_states = final_states + " " + states[i]
        i = i + 1

    #print final states:
    f.write("0 ")

    f.write(final_states)
    f.write('\n')


    f.write("0 & 1")
    f.write('\n')


    #print transitions in M1
    M1.alphabet.append('&')
    for state in M1.states:
        for value in M1.alphabet:
            transitions = M1.transitions[state][value]
            if transitions is not None:
                for transition in transitions:
                    f.write(f'{M1_to_M[state]} {value} {M1_to_M[transition]}')
                    f.write('\n')

                    if transition in M1.final_states:
                        f.write(f"{M1_to_M[transition]} & 1")
                        f.write('\n')
    f.close()

def check(the_set, w, i, Below=True, pop=True):

    if Below:
        try:
            if not pop:

                if isinstance(w[i], tuple) and w[i][0] in the_set:
                    return True

                if w[i] in the_set:
                    return True
            else:
                if isinstance(w[i], tuple) and w[i][0] in the_set:
                    return True

                if w[i-1] in the_set:
                    return True

        except:
            return False

    if not Below:
        try:
            #if w[i+1] in the_set:
                #return True

            if i == len(w) -1:
                return True

            #if isinstance(w[i-1], tuple) and w[i-1][0] in the_set:
                #return True

            if w[i] in the_set:
                return True
        except:
            return False

    return False

def re_to_nfa(w):

    stack = []
    stack.append("$")
    stack_pos = 0
    size = len(w)

    #"#" = "⊣" end marker
    w.append("#")

    i = 0
    marker = True
    placeholder = ""
    file_name = "nfa_file"
    file_counter = 1
    while(marker):
        #break
        #print(f'stack is {stack}, i = {i}, stack_pos = {stack_pos}')

        try:
            value = w[i]
        except:
           value = None

        #Rule 1: a ∈ Σ
        if check({"$", "(", "|", "T"}, stack, stack_pos, Below=True, pop=False) and value.isalnum():
            stack.append(value)
            stack_pos = stack_pos + 1
            i = i + 1
            continue

        #Rule 2: (, ε → (
        if check({"$", "(", "|", "T"}, stack, stack_pos, Below=True, pop=False) and value == "(":
            stack.append(value)
            stack_pos = stack_pos + 1
            i = i + 1
            continue

        #Rule 3: ), ε → )
        if check({"E"}, stack, stack_pos, Below=True, pop=False) and value == ")":
            stack.append(value)
            stack_pos = stack_pos + 1
            i = i + 1
            continue

        #Rule 4: |, ε → |
        if check({"E"}, stack, stack_pos, Below=True, pop=False) and value == "|":
            stack.append(value)
            stack_pos = stack_pos + 1
            i = i + 1
            continue

        #Rule 5: *, ε → *
        if check({"P"}, stack, stack_pos, Below=True, pop=False) and value == "*":
            stack.append(value)
            stack_pos = stack_pos + 1
            i = i + 1
            continue

        #Rule 6: ε, E|M → E
        if stack_pos > 2 and isinstance(stack[-3], tuple) and isinstance(stack[-2], str) and isinstance(stack[-1], tuple) and stack[-3][0] == "E" and stack[-2] == "|" and stack[-1][0] == "M":

            b = stack.pop()[1]
            stack.pop()
            a = stack.pop()[1]

            union_file = file_name + str(file_counter)
            file_counter = file_counter + 1

            union_nfa(a, b, union_file)

            #no need to keep previous files
            os.remove(a)
            os.remove(b)


            stack.append(("M", union_file))
            stack_pos = stack_pos - 2
            continue

        #Rule 7: ε, M → E
        if check({"$", "("}, stack, stack_pos, Below=True, pop=True) and isinstance(stack[-1], tuple) and stack[-1][0] == "M":
            a = stack.pop()[1]
            stack.append(("E", a))
            continue

        #Rule 8: ε, ε → M
        if check({"$", "(", "|"}, stack, stack_pos, Below=True, pop=False) and check({"|", ")", "#"}, w, i, Below=False, pop=False):

            epsilon_file = file_name + str(file_counter)
            file_counter = file_counter + 1

            string_nfa("", epsilon_file)

            stack.append(("M", epsilon_file))
            stack_pos = stack_pos + 1
            continue

        #Rule 9: ε,T → M
        if isinstance(stack[-1], tuple) and stack[-1][0] == "T" and check({"|", ")", "#"}, w, i, Below=False, pop=False):
            a = stack.pop()[1]
            stack.append(("M", a))
            continue

        #Rule 10: ε,TF → T
        if stack_pos > 1 and isinstance(stack[-2], tuple) and isinstance(stack[-1], tuple) and stack[-2][0] == "T" and stack[-1][0] == "F":
            b = stack.pop()[1]
            a = stack.pop()[1]

            concat_file = file_name + str(file_counter)
            file_counter = file_counter + 1

            concat_nfa(a, b, concat_file)
            
            #no need to keep previous files
            os.remove(a)
            os.remove(b)

            stack.append(("T", concat_file))
            stack_pos = stack_pos - 1
            continue

        #Rule 11: ε, F → T
        if check({"$", "(", "|"}, stack, stack_pos, Below=True, pop=True) and isinstance(stack[-1], tuple) and stack[-1][0] == "F":
            a = stack.pop()[1]
            stack.append(("T", a))
            continue

        #Rule 12: ε, P* → F
        if stack_pos > 1 and isinstance(stack[-2], tuple) and stack[-2][0] == "P" and stack[-1] == "*":
            b = stack.pop()
            a = stack.pop()[1]

            star_file = file_name + str(file_counter)
            file_counter = file_counter + 1
            
            star_nfa(a, star_file)
            os.remove(a) # no need to keep past files/NFAs

            stack.append(("F", star_file))
            stack_pos = stack_pos - 1
            continue

        #Rule 13: ε, P → F
        if isinstance(stack[-1], tuple) and stack[-1][0] == "P" and ((i < size and w[i] != "*") or (i == size)):
            a = stack.pop()[1]
            stack.append(("F", a))
            continue

        #Rule 14: ε, a → P
        try:
            if stack[-1].isalnum():
                a = stack.pop()

                symbol_file = file_name + str(file_counter)
                file_counter = file_counter + 1

                string_nfa(a, symbol_file)

                stack.append(("P", symbol_file))
                continue
        except:
            pass

        #Rule 15: ε, (E) → P
        if stack_pos > 2 and stack[-3] == "(" and isinstance(stack[-2], tuple) and stack[-2][0] == "E" and stack[-1] == ")":
            stack.pop()
            a = stack.pop()[1]
            stack.pop()

            stack.append(("P", a))
            stack_pos = stack_pos - 2
            continue
        marker = False
    
    return file_name + str(file_counter - 1)

def match(M, w):

    if w == "" and M.start_state in M.final_states:
        return (True, [])

    curr_states = []
    curr_states.append(M.start_state)
    graph = dict()

    marker = 0
    graph[(M.start_state, marker)] = None

    while marker < len(w) +1:

        if marker < len(w):
            letter = w[marker]
        else:
            letter = None

        marker = marker + 1
        next_states = []
        #visited = set()


        for curr_state in curr_states:

            # check for epsilon transitions
            if M.transitions[curr_state]['&']:
                #initialize epsilon_states and graph
                epsilon_states = M.transitions[curr_state]['&']

                for state in epsilon_states:
                    try:
                        graph[(state, marker-1)]
                    except:
                        graph[(state, marker-1)] = (curr_state, marker-1)
                        curr_states.append(state)

                #check for possible epsilon chain
                for state in epsilon_states:
                    try:
                        graph[(state, marker-1)]
                    except:
                        curr_states.append(state)


                    if M.transitions[state]['&']:
                        for epsilon in M.transitions[state]['&']:
                            try:
                                graph[(state, marker-1)]
                            except:
                                epsilon_states.append(epsilon)
                                graph[(epsilon, marker-1)] = (state, marker-1)



            #build graph
            next_set = set()
            if letter:
                try:
                    M.transitions[curr_state][letter]
                except:
                    return False

                for state in M.transitions[curr_state][letter]:
                    graph[(state, marker)] = (curr_state, marker-1)
                    if state not in next_set:
                        next_states.append(state)
                        next_set.add(state)

        curr_states = next_states

    # construct the path:
    path = []
    state = ''
    start_state = M.start_state

    for final_state in M.final_states:
        if (final_state, len(w)) in graph:

            state = final_state
            path.append((state, None))
            i = len(w)

            while (i > 0):
                next_state = graph[(state, i)][0]

                if graph[(state, i)][1] == i:
                    path.append((next_state, '&'))
                    state = next_state
                else:
                    state = next_state
                    i = i - 1
                    path.append((next_state, w[i]))

            # check if path started with an epsilon transition

            while state != start_state:
                state = graph[(state, 0)][0]
                path.append((state, '&'))

            path.reverse()
            return (True, path)


    return False
