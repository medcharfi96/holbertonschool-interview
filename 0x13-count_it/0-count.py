#!/usr/bin/python3
""" task 0 """


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

    if hot.status_code == 200:
        pub = hot.json().get("data").get("children")
        hot_list += [ART.get("data").get("title") for ART in pub]
        after = hot.json().get("data").get("after")
        if after is not None:
            count_words(subreddit, word_list, hot_list, 1, after)
        if init == 0:
            hot_str = " ".join(hot_list)
            word_spt = hot_str.split(" ")
            tab1 = sorted(word_list)
            retour = []
            for w in tab1:
                numero = len(
                    list(
                        filter(
                            lambda hot_w: hot_w.lower() == w.lower(),
                            word_spt)))
                if numero != 0:
                    retour.append([word, numero])
            if len(retour) != 0:
                i = 0
                while i < len(retour) - 1:
                    if retour[i + 1][0] is not None and
                    retour[i][0] == retour[i + 1][0]:
                        retour[i][1] += retour[i + 1][1]
                        retour.pop(i + 1)
                        retour.append([None, None])
                        i -= 1
                    i += 1
                r = list(filter(lambda x: x != [None, None], retour))
                r_sorted = sorted(r, key=lambda x: (x[1]), reverse=True)
                for i in r_sorted:
                    print(*i, sep=": ")
