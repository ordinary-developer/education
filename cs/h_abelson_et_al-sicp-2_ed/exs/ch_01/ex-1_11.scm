#lang sicp

; [exercise] =>
; A function `f` is defined by the rule that
;          _
;         | n if n < 3
; f(n) = <
;         | f(n - 1) + 2f(n - 2) + 3f(n - 3) if n >= 3
;          _
; Write a procedures that computes `f`
; by means of a recursive process.
; Write a procedure that computes `f`
; by means of an iterative process.



; -------------
; [solution] =>
; recursive process
; recursive process
(display "the recursive process ->") (display "\n")
(define (f-recur n)
    (if (< n 3) n
        (+ (f-recur (- n 1))
           (* 2 (f-recur (- n 2)))
           (* 3 (f-recur (- n 3))))))

(f-recur 0)
(f-recur 1)
(f-recur 2)
(f-recur 3)
(f-recur 5)
(f-recur 10)
(f-recur 17) 
(display "\n")

; iterative process (first version)
(display "the iterative process (first version) ->") (display "\n")
(define (f-iter-01 n)
    (define (iter a b c counter)
        (if (= counter 0)
            c
            (iter (+ a (* 2 b) (* 3 c)) a b (- counter 1))))

    (iter 2 1 0 n))

(f-iter-01 0)
(f-iter-01 1)
(f-iter-01 2)
(f-iter-01 3)
(f-iter-01 5)
(f-iter-01 10)
(f-iter-01 17) 
(display "\n")

; iterative process (second version)
(display "the iterative process (second version) ->") (display "\n")
(define (f-iter-02 n)
    (define (iter a b c counter)
        (if (> counter n)
            c
            (iter (+ a (* 2 b) (* 3 c)) a b (+ counter 1))))
            
    (iter 2 1 0 1))

(f-iter-02 0)
(f-iter-02 1)
(f-iter-02 2)
(f-iter-02 3)
(f-iter-02 5)
(f-iter-02 10)
(f-iter-02 17) 
(display "\n") 

; iterative process (third version)
(display "the iterative process (third version) ->") (display "\n")
(define (f-iter-03 n)
    (define (iter a b c counter)
        (if (= counter n)
            c
            (iter (+ a (* 2 b) (* 3 c)) a b (+ counter 1))))

    (iter 2 1 0 0))

(f-iter-03 0)
(f-iter-03 1)
(f-iter-03 2)
(f-iter-03 3)
(f-iter-03 5)
(f-iter-03 10)
(f-iter-03 17) 
(display "\n")

