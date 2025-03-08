#lang sicp

; [exercise] =>
; Define a procedure that takes three numbers
; as arguments and returns the sum of the squares of the two
; larger numbers



; [solution] =>
(define (sum-of-squares-of-two-larger p1 p2 p3)
    (define (min2 p1 p2) (if (< p1 p2) p1 p2))
    (define (min3 p1 p2 p3) (min2 p1 (min2 p2 p3)))
    (define (max2 p1 p2) (if (> p1 p2) p1 p2))
    (define (max3 p1 p2 p3) (max2 p1 (max2 p2 p3)))

    (define (square p) (* p p))

    (+ (square (max3 p1 p2 p3))
       (square (- (+ p1 p2 p3)
                  (max3 p1 p2 p3)
                  (min3 p1 p2 p3)))))


(define assert (= 5
                  (sum-of-squares-of-two-larger 0 1 2)
                  (sum-of-squares-of-two-larger 0 2 1)
                  (sum-of-squares-of-two-larger 1 0 2)
                  (sum-of-squares-of-two-larger 1 2 0)
                  (sum-of-squares-of-two-larger 2 0 1)
                  (sum-of-squares-of-two-larger 2 1 0)))

assert
