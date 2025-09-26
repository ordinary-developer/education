; [exercise] =>
; Alyssa P.Hacker doesn't see
; why `if` needs to be provides as a special form.
; "Why can't I just define it as an ordinary procedure 
;  in terms of cond?" she asks.
; Alyssa's friend Eva Lu Ator claims this can indeed be done,
; and she defines a new version of `if`:
; ```
; (define (new-if predicate then-clause else-cluase)
;     (cond (predicate then-clause)
;           (else else-clause)))
; ```
;
; Eva demonstrates the program for Alyssa:
; ```
; (new-if (= 2 3) 0 5)
; 5
; (new-if (= 1 1) 0 5)
; 0
; ```
;
; Deligeted, Alyssa uses `new-if` to rewrite the square-root program:
; ```
; (define (sqrt-iter guess x)
;    (new-if (good-enough? guess x)
;            guess
;            (sqrt-iter (improve guess x) x)))
; ```
;
; What happens when Alyssa attempts t ouse this to compute square roots? Explain.


; -------------
; [solution] =>
; Because `new-if` is a procedure its parameters must be evaluated,
; so `sqrt-iter` will be called infinetly.
; (It must always calculate the 'else' value
; (even in the case when 'predicate' is #t))