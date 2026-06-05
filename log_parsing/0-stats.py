#!/usr/bin/python3
"""Module pour traiter les statistiques des logs"""
import sys


def print_stats(stats, total_size):
    """Affiche les statistiques accumulées"""
    print('File size: {}'.format(total_size))
    for s_code, count in sorted(stats.items()):
        if count:
            print('{}: {}'.format(s_code, count))


if __name__ == "__main__":
    stats = {
        '200': 0, '301': 0, '400': 0, '401': 0,
        '403': 0, '404': 0, '405': 0, '500': 0
    }
    total_size = 0
    line_count = 0

    try:
        for line in sys.stdin:
            line_count += 1
            matches = line.split()

            try:
                # Récupération de la taille (dernier élément)
                total_size += int(matches[-1])
                # Récupération du code (avant-dernier élément)
                status_code = matches[-2]
                if status_code in stats:
                    stats[status_code] += 1
            except (IndexError, ValueError):
                continue

            if line_count % 10 == 0:
                print_stats(stats, total_size)

        print_stats(stats, total_size)

    except KeyboardInterrupt:
        print_stats(stats, total_size)
        raise
