#lang sicp

(define (abs1 x)
    (cond ((> x 0) x)
          ((= x 0) 0)
          ((< x 0) (- x))))

(abs1 (- 42))
(abs1 0)
(abs1 42)


(define (abs2 x)
    (cond ((< x 0) (- x))
          (else x)))

(abs2 (- 42))
(abs2 0)
(abs2 42)


(define (abs3 x)
    (if (< x 0)
        (- x)
        x))
(abs3 (- 42))
(abs3 0)
(abs3 42)


(define x 3)
(and (> x 5) (< x 10))


(define (gt-or-eq x y)
    (or (> x y) (= x y)))
(gt-or-eq 17 42)
(gt-or-eq 42 17)


(define (gt-or-eq2 x y)
    (not (< x y)))
(gt-or-eq2 17 42)
(gt-or-eq2 42 17)
