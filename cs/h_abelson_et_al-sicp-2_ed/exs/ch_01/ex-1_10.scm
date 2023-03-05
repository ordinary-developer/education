#lang sicp

; [exercise] =>
; The following procedure computes a mathematical function
; called Ackermann's function.
;; ```
; (define (A x y)
;   (cond ((= y 0) 0)
;         ((= x 0) (* 2 y))
;         ((= y 1) 2)
;         (else (A (- x 1) (A x (- y 1))))))
; ```
;
; What are the values of the following expressions?
; ```
; (A 1 10)
; (A 2 4)
; (A 3 3)
; ```
;
; Consider the following procedures,
; where `A` is the procedures defined above:
; ```
; (define (f n) (A 0 n))
; (define (g n) (A 1 n))
; (define (h n) (A 2 n))
; (define (k n) (* 5 n n))
; ```
;
; Give concise mathematical defintions for the functions
; computed by the procedures `f`, `g`, and `h`
; for positive integer values of n.
;
; For example, `(k n)` computes 5n^2.



; -------------
; [solution] =>
(define (A x y)
    (cond ((= y 0) 0)
          ((= x 0) (* 2 y))
          ((= y 1) 2)
          (else (A (- x 1) (A x (- y 1))))))

(display "'Base function (A x y)' ->") (display "\n")
(display "(A 1 10) = ") (display (A 1 10)) (display "\n")
(display "(A 2 4) = ") (display (A 2 4)) (display "\n")
(display "(A 3 3) = ") (display (A 3 3)) (display "\n")
(display "\n")

; let's consider the `(f n)` function:
; f(n) = A(0, n) = 2 * n (by definition)

; verification:
(display "'(f n) = (A 0 n)' ->") (display "\n")
(define (f n) (A 0 n))
(define (f-reduced n) (* 2 n))
(display (= (f 1) (f-reduced 1))) (display "\n")
(display (= (f 5) (f-reduced 5))) (display "\n")
(display (= (f 10) (f-reduced 10))) (display "\n")
(display "\n")


; let's consider the `(g n)` function:
; g(n) = A(1, n) = A(1 - 1, A(1, n - 1)) = A(0, A(1, n - 1)) = 2 * A(1, n - 1) =
; = 2 * A(1 - 1, A(1, (n - 1) - 1)) = 2 * A(0, A(1, n - 2)) = 2 * 2 * A(1, n - 2) = ... =
; = 2^k * A(1, n - k) = 2^(m - 1) * A(1, n - (m - 1))
;
; let m = n, then 
; g(n) = 2^(n - 1) * A(1, n - (n - 1)) = 2^(n - 1) * A(1, 1) = 2^(n - 1) * 2 = 2^n
; 
; so, g(n) = 2^n

; verification
(display "'(g n) = (A 1 n)' ->") (display "\n")
(define (g n) (A 1 n))
(define (g-reduced n)
    (define (pow x exp)
        (define (iter product counter)
            (if (> counter exp)
                product
                (iter (* x product) (+ counter 1))))
        (iter 1 1))
    (pow 2 n))
(display (= (g 1) (g-reduced 1))) (display "\n")
(display (= (g 5) (g-reduced 5))) (display "\n")
(display (= (g 10) (g-reduced 10))) (display "\n")
(display "\n")


; let's consider the `(h n)` function:
; h(n) = A(2, n) = A(1, A(2, n')) | {n' = (n - 1)} = A(1, y') | { y' = A(2, n'), n' = n - 1} 
; = 2^(y') (according to the previous function g(n) = A(1 n)) 
; = 2^(A(2, n')) = 2^(A(2, n - 1)) = 2^(h(n - 1))
;
; so, h(h) = 2^(h(n - 1))

; verification
(display "'(h n) = (A 2 n)' ->") (display "\n")
(define (h n) (A 2 n))
(define (h-reduced n)
    (define (pow x exp)
        (define (iter accum counter)
            (if (> counter exp) accum (iter (* x accum) (+ counter 1))))
        (iter 1 1))

    ; the next two lines can be used interchangeably
    ;(if (= n 0) 1 (pow 2 (h-reduced (- n 1))))) 
    (if (= n 1) 2 (pow 2 (h-reduced (- n 1)))))
(display (= (h 1) (h-reduced 1))) (display "\n")
(display (= (h 2) (h-reduced 2))) (display "\n")
(display (= (h 3) (h-reduced 3))) (display "\n")
(display "\n")
; now `(h 5)`, `(h 6)` and so on due to stack overflow of the `pow` function



; -------------
; [aux notes to the solution]
(display "'auxiliary implementations for the H function' ->") (display "\n")

; an iterative process
(define (h-reduced-iter-01 n)
    (define (pow x exp)
        (define (iter accum counter)
            (if (> counter exp) accum (iter (* x accum) (+ counter 1))))
        (iter 1 1))

    (define (iter accum counter)
        (if (= counter 0)
            accum
            (iter (pow 2 accum) (- counter 1))))

    (iter 1 n))

; an iterative process with a block structure
(define (h-reduced-iter-02 n)
    (define (pow x exp)
        (define (iter accum counter)
            (if (> counter exp) accum (iter (* x accum) (+ counter 1))))
        (iter 1 1))

    (define (iter accum counter)
        (if (= counter n)
            accum
            (iter (pow 2 accum) (+ counter 1))))
            
    (iter 1 0))

; an iterative process with a block structure (another variant)
(define (h-reduced-iter-03 n)
    (define (pow x exp)
        (define (iter accum counter)
            (if (> counter exp) accum (iter (* x accum) (+ counter 1))))
        (iter 1 1))

    (define (iter accum counter)
        (if (> counter n)
            accum
            (iter (pow 2 accum) (+ counter 1))))
            
    (iter 1 1))

(display (= (h 2) (h-reduced-iter-01 2) (h-reduced-iter-02 2) (h-reduced-iter-03 2))) (display "\n")
(display (= (h 3) (h-reduced-iter-01 3) (h-reduced-iter-02 3) (h-reduced-iter-03 3))) (display "\n")
(display (= (h 4) (h-reduced-iter-01 4) (h-reduced-iter-02 4) (h-reduced-iter-03 4))) (display "\n")
(display "\n")
