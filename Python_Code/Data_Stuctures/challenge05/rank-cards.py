#!/usr/bin/env python3

'''
Title: rank-cards.py
Abstract: A Program that ranks cards and prints out the names of the cardholders in the order of card ranking
Author: Josue Rocha
Email: jrocha3@student10.cse.nd.edu
Estimate: 1 hour 
Date: 03/23/2023
'''

# set for face card values to make comparison easier
face_card = {
    'J' : 11,
    'Q' : 12,
    'K' : 13,
    'A' : 14
}

# set for suit values (relative to each other) to make comparison easier
suits = {
    'C' : 1,
    'D' : 2,
    'H' : 3,
    'S' : 4
}
Hand = {}
file_name = input('Enter file name: ')
# open the file specified by the user
the_file = open(file_name, 'r')
the_file = the_file.read().splitlines()
size = int(the_file[0])

for i in range(1, size+1):
    hand = the_file[i].split()
    
    if hand[1] in face_card: # check to see if the card is a face card
        rank = face_card[hand[1]]
    else:
        rank = int(hand[1])
    suit = suits[hand[2]] # record the suit as an integer value
    value = []
    value.append(rank)
    value.append(suit)

    # add the the person's hand to the Hand dict
    Hand[hand[0]] = value

Hand = list(Hand.items())
#sort the Hand dict
Hand = sorted(Hand, key=lambda h: (h[1][0], h[1][1]), reverse=True)

for index, hand in enumerate(Hand, 1):
    print(list(hand)[0],end='')
    # print commas after all of the people except for the last one
    if index < size:
        print(', ',end='')
print()
