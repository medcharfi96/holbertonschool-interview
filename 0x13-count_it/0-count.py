#!/usr/bin/python3
""" task """
from operator import itemgetter
import requests


def count_words(subreddit, word_list, hot_list=[], init=0, after="null"):
    """
	description
	"""

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    agent = {"User-Agent": "linux:1:v2.1 (by /u/heimer_r)"}
    payload = {"limit": "100", "after": after}
    hot = requests.get(url, headers=agent,
                       params=payload, allow_redirects=False)

    mot = {}
    titre = []
    nbr = {}
    for kelma in word_list:
        if kelma not in nbr:
            nbr[kelma] = 0
    if hot.status_code == 200:
        fils = hot.json().get('data').get('children')
        for j in fils:
            titre.append(j.get('data').get('title'))
        for title in titre:
            for key, valeur in nbr.items():
                copier = title[:]
                couper = copier.lower().split(key.lower())
                nbr[key] =  nbr[key]  + (len(couper) - 1)
        fnl = {}
        for k in nbr:
            if  k.lower() in fnl and nbr[k] != 0:
                fnl[k.lower()] += nbr[k]
            elif nbr[k] !=0  and  k.lower() not in fnl :
                fnl[k.lower()] = nbr[k]
            else:
                pass
        val_tri = sorted(fnl.values(), reverse=True)
        resultat = {}

        for i in val_tri:
            for j in fnl.keys():
                if fnl[j] == i:
                    resultat[j] = fnl[j]
        for i in resultat.keys():
            print("{}: {}".format(i, resultat[i]))