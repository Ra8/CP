n, k, r = map(int, raw_input().split())

cameras = [False] * (n + 2)

for _ in range(k):
    loc = int(raw_input())
    cameras[loc] = True

window_start = 1
window_end = r
curr_cams = 0
for i in range(window_start, window_end + 1):
    curr_cams += cameras[i]
added = 0
while window_end <= n:
    if curr_cams < 2:
        cameras[window_end] = True
        curr_cams += 1
        added += 1
        if curr_cams < 2:
            cameras[window_end - 1] = True
            curr_cams += 1
            added += 1

    curr_cams -= cameras[window_start]
    window_start += 1
    window_end += 1
    curr_cams += cameras[window_end]

print added
