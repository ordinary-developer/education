; [exercise] =>
; Newton's method for cube roots is based on the fact
; that if `y` is an approximation to the cube root of `x`,
; then a better approximation is given by the value
;
;  (x/y^2 + 2y) / 3
; 
; Use thise formula to implement a cube-root procedure
; analogous to the square-root procedure


; -------------
; [solution] =>
#lang sicp

; core
(define (cube-root x)
    (define (cube-root-iter guess x)
        (if (good-enough? guess x)
            guess
            (cube-root-iter (improve guess x) x)))

    (define (good-enough? guess x) (< (abs (- (cube guess) x)) 0.001))
    (define (abs x) (if (< x 0) (- x) x))
    (define (cube x) (* x x x))
    (define (improve guess x)
        (/ (+ (/ x (square guess)) (* 2 guess)) 3))
    (define (square x) (* x x))

    (cube-root-iter 1.0 x))

; util functions
(define (output-test name ret)
    (display (if ret "[  OK  ]" "[FAILED]"))
    (display " ") (display name) (newline))

(define (abs num) (if (< num 0) (- num) num))
(define (are-equal num1 num2) (< (abs (- num1 num2)) 0.001))

; test running
(display "running tests...") (newline)

(define assert-01
    (and
        (are-equal 2 (cube-root 8))
        (are-equal 2 (cube-root 8))))
(output-test "cube root with integer numbers" assert-01)

(define assert-02
    (and
        (are-equal 2.5 (cube-root 15.625))
        (are-equal 3.7 (cube-root 50.653))
        (are-equal 4.9 (cube-root 117.649))))
(output-test "cube root with real numbers" assert-02)

(define assert-03
    (and
        (are-equal (- 2) (cube-root (- 8)))
        (are-equal (- 2.5) (cube-root (- 15.625)))))
(output-test "cube-root with negative numbers" assert-03)
