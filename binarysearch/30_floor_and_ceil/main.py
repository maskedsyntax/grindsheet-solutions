def getFloorAndCeil(a, n, x):
    l, r = 0, n-1

    f, c = -1, -1

    while l <= r:
        mid = l + (r - l)//2
        if a[mid] == x:
            return (a[mid], a[mid])
        elif a[mid] < x:
            f = a[mid]
            l = mid + 1
        else: 
            c = a[mid]
            r = mid - 1

    
    return (f, c)