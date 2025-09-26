#lang sicp

(define (sqrt-01 x)
    (define (square x) (* x x))
    (define (abs x) (if (< x 0) (- x) x))
    (define (good-enough? guess x)
        (< (abs (- (square guess) x)) 0.001))
    (define (improve guess x) (average guess (/ x guess)))
    (define (average x y) (/ (+ x y) 2))
    (define (sqrt-iter guess x)
        (if (good-enough? guess x)
            guess
            (sqrt-iter (improve guess x) x)))
    (sqrt-iter 1.0 x))

(sqrt-01 17)
(sqrt-01 42)


(define (sqrt-02 x)
    (define (square a) (* a a))
    (define (abs a) (if (< a 0) (- a) a))
    (define (good-enough? guess)
        (< (abs (- (square guess) x)) 0.001))
    (define (average a b) (/ (+ a b) 2))
    (define (improve guess)
        (average guess (/ x guess)))
    (define (sqrt-iter guess)
        (if (good-enough? guess)
            guess
            (sqrt-iter (improve guess))))
    (sqrt-iter 1.0))

(sqrt-02 17)
(sqrt-02 42)
