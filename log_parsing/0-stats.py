#!/usr/bin/python3
"""Log parsing"""
import sys
import re

status_codes = ["200", "301", "400", "401",
                "403", "404", "405", "500"]


def print_stats(total_size, stats):
    """Print statistics"""
    print("File size: {}".format(total_size))

    for code in status_codes:
        if stats[code] != 0:
            print("{}: {}".format(code, stats[code]))


if __name__ == "__main__":
    total_size = 0
    line_count = 0

    stats = {code: 0 for code in status_codes}

    pattern = re.compile(
        r'^(\d+\.\d+\.\d+\.\d+) - '
        r'\[(.*?)\] '
        r'"GET /projects/260 HTTP/1\.1" '
        r'(\d+) (\d+)$'
    )

    try:
        for line in sys.stdin:
            match = pattern.match(line.strip())

            if match:
                status_code = match.group(3)
                file_size = int(match.group(4))

                total_size += file_size

                if status_code in stats:
                    stats[status_code] += 1

            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, stats)

    except KeyboardInterrupt:
        print_stats(total_size, stats)
        raise

    print_stats(total_size, stats)
