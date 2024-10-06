#lang sicp

; Let n be a parameter that measures the size of the problem,
; and let R(n) be the amount of resources
; the process requires for a problem of size n.

; We say that R(n) has order of growth Theta(f(n)), written R(N) = Theta(f(n)),
; if there are positive constants k1 and k2 independent of n
; such that k1 * f(n) <= R(n) <= k2 * f(n)
; for any sufficiently large value of n.

; For large n, the value R(n) is sandwitched between k1 * f(n) and k2 * f(n).
