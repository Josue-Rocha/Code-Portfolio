#!/usr/bin/env python3

import os
import sys
import requests

# Constants

ISGD_URL = 'http://is.gd/create.php'

# Functions

def usage(status=0):
    ''' Display usage information and exit with specified status '''
    print('''Usage: {} [options] URL_OR_SUBREDDIT

    -s          Shorten URLs using (default: False)
    -n LIMIT    Number of articles to display (default: 10)
    -o ORDERBY  Field to sort articles by (default: score)
    -t TITLELEN Truncate title to specified length (default: 60)
    '''.format(os.path.basename(sys.argv[0])))
    sys.exit(status)

def load_reddit_data(url):
    ''' Load reddit data from specified URL into dictionary

    >>> len(load_reddit_data('https://reddit.com/r/nba/.json')) >= 25
    True

    >>> load_reddit_data('linux')[0]['data']['subreddit']
    'linux'
    '''
    # TODO: Verify url parameter (if it starts with http, then use it,
    # otherwise assume it is just a subreddit).
    headers  = {'user-agent': 'reddit-{}'.format(os.environ.get('USER', 'cse-20289-sp23'))}
    if url == None:
        usage(1)
    elif url.startswith('http'):
        if not url.endswith('.json'):
            url += '.json'
        response = requests.get(url, headers=headers)
    else:
        URL = f'https://reddit.com/r/{url}/.json'
        response = requests.get(URL, headers=headers)
    data = response.json()
    data = data['data']['children']
    return data

def shorten_url(url):
    ''' Shorten URL using is.gd service

    >>> shorten_url('https://reddit.com/r/aoe2')
    'https://is.gd/dL5bBZ'

    >>> shorten_url('https://cse.nd.edu')
    'https://is.gd/3gwUc8'
    '''
    # TODO: Make request to is.gd service to generate shortened url.
    response = requests.get(ISGD_URL, params={'format' : 'json', 'url' : url})
    response = response.text
    short_url = ''
    for i, c in enumerate(response):
        if i > 14:
            if c == '"':
                break
            short_url += c
    return short_url


def print_reddit_data(data, limit=10, orderby='score', titlelen=60, shorten=False):
    ''' Dump reddit data based on specified attributes '''
    # TODO: Sort articles stored in data list by the orderby key, and then
    # print out each article's index, title, score, and url using the following
    # format:
    #
    #   print(f'{index:4}.\t{title} (Score: {score})\n\t{url}')
    #
    # Note: Trim or modify the output based on the keyword arguments to the function.
    #inner_dict = {}
    reverse = orderby == 'score'
    articles = sorted(data, key=lambda d: d['data'][orderby], reverse=reverse)

    for index, article in enumerate(articles[:limit], 1):

        if index > 1:
            print()

        score = article['data']['score']
        title = article['data']['title'][:titlelen]
        if shorten:
             url  = shorten_url(article['data']['url'])
        else:
             url  = article['data']['url']
        print(f'{index:4}.\t{title} (Score: {score})\n\t{url}')
        
def main():
    # TODO: Parse command line arguments
    arguments = sys.argv[1:]
    url       = None
    limit     = 10
    orderby   = 'score'
    titlelen  = 60
    shorten   = False

    # TODO: Load data from url and then print the data
    for index, argument in enumerate(arguments):
        if argument.startswith('-'):
            if argument == "-s":
                shorten = True
            elif argument == '-n':
                limit = int(arguments[index + 1])
            elif argument == '-o':
                orderby = arguments[index + 1]
            elif argument == '-t':
                titlelen = int(arguments[index + 1])
            elif argument == '-h':
                usage(0)
            else:
                usage(1)
        url = f'{arguments[index]}'
    data = load_reddit_data(url)
    print_reddit_data(data, limit=limit, orderby=orderby, titlelen=titlelen, shorten=shorten)

# Main Execution

if __name__ == '__main__':
    main()

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:
