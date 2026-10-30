# !/usr/bin/python3
""" Count occurrences of keywords in hot Reddit articles. """
import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Recursively queries Reddit and counts keyword occurrences in titles.
    """
    if counts is None:
        counts = {}

    if not isinstance(word_list, list) or not word_list:
        return

    if not subreddit:
        return

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)

    headers = {
        "User-Agent": "HolbertonSchool/1.0"
    }

    params = {
        "limit": 100,
        "after": after
    }

    try:
        response = requests.get(
            url,
            headers=headers,
            params=params,
            allow_redirects=False
        )
    except requests.RequestException:
        return

    if response.status_code != 200:
        return

    try:
        data = response.json().get("data", {})
        children = data.get("children", [])
    except (ValueError, AttributeError):
        return

    keywords = {}

    for word in word_list:
        word = word.lower()
        keywords[word] = keywords.get(word, 0)

    for child in children:
        title = child.get("data", {}).get("title", "").lower()
        words = title.split()

        for word in words:
            cleaned = word.strip(".,!?;:'\"()[]{}")

            if cleaned in keywords:
                keywords[cleaned] += 1

    for word, count in keywords.items():
        counts[word] = counts.get(word, 0) + count

    after = data.get("after")

    if after is not None:
        return count_words(subreddit, word_list, after, counts)

    results = sorted(
        counts.items(),
        key=lambda item: (-item[1], item[0])
    )

    for word, count in results:
        if count > 0:
            print("{}: {}".format(word, count))
