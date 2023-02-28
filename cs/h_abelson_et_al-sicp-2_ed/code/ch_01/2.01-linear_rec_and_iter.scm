#lang sicp

(display "=> Linear Recursion and Iteration") (newline)

(define (factorial-01 n)
    (if (= n 1)
        1
        (* n (factorial-01 (- n 1)))))
        
(factorial-01 6)


(define (factorial-02 n)
    (fact-iter 1 1 n))

(define (fact-iter product counter max-count)    
    (if (> counter max-count)
        product
        (fact-iter (* counter product)
                   (+ counter 1)
                   max-count)))

(factorial-02 6)


(define (factorial-03 n)
    (define (iter product counter)
        (if (> counter n)
            product
            (iter (* counter product)
                  (+ counter 1))))
    (iter 1 1))

(factorial-03 6)
