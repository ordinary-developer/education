;; [exercise]
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



;; [solution]
(define (A x y)
    (cond ((= y 0) 0)
          ((= x 0) (* 2 y))
          ((= y 1) 2)
          (else (A (- x 1) (A x (- y 1))))))

(display "(A 1 10) = ")(display (A 1 10))(newline)
(display "(A 2 4) = ")(display (A 2 4))(newline)
(display "(A 3 3) = ")(display (A 3 3))(newline)


; let's consider the `(f n)` function:
; f(n) = A(0, n) = 2 * n (by definition)
;
; verification:
(define (f n) (A 0 n))
(define (f_reduced n) (* 2 n))
(display (= (f 1) (f_reduced 1))) 
    (display " ") (display (= (f 5) (f_reduced 5))) 
    (display " ") (display (= (f 10) (f_reduced 10))) (newline)


; let's consider the `(g n)` function:
; g(n) = A(1, n) = A(1 - 1, A(1, n - 1)) = A(0, A(1, n - 1)) = 2 * A(1, n - 1) =
; = 2 * A(1 - 1, A(1, (n - 1) - 1)) = 2 * A(0, A(1, n - 2)) = 2 * 2 * A(1, n - 2) = ... =
; = 2^k * A(1, n - k) = 2^(m - 1) * A(1, n - (m - 1))
;
; let m = n, then 
; g(n) = 2^(n - 1) * A(1, n - (n - 1)) = 2^(n - 1) * A(1, 1) = 2^(n - 1) * 2 = 2^n
; 
; so, g(n) = 2^n
;
; verification
(define (g n) (A 1 n))

(define (g_reduced n) 
    (define (pow x n)
        (define (iter product counter)
            (if (> counter n)
                product
                (iter (* x product) (+ counter 1))))
        (iter 1 1))
    (pow 2 n))

(display (= (g 1) (g_reduced 1)))
    (display " ") (display (= (g 5) (g_reduced 5)))
    (display " ") (display (= (g 10) (g_reduced 10))) (newline)


; let's consider the `(h n)` function:
; h(n) = A(2, n) = A(1, A(2, n')) | {n' = (n - 1)} = A(1, y') | { y' = A(2, n'), n' = n - 1} 
; = 2^(y') (according to the previous function g(n) = A(1 n)) 
; = 2^(A(2, n')) = 2^(A(2, n - 1)) = 2^(h(n - 1))
;
; so, h(h) = 2^(h(n - 1))
;
; verification
(define (h n) (A 2 n))

(define (h_reduced n)
    (define (pow x n)
        (define (iter accum counter)
            (if (> counter n) accum (iter (* x accum) (+ counter 1))))
        (iter 1 1))

    ;(if (= n 0) 1 (pow 2 (h_reduced (- n 1)))))    
    (if (= n 1) 2 (pow 2 (h_reduced (- n 1)))))    

(display (= (h 1) (h_reduced 1)))
     (display " ") (display (= (h 2) (h_reduced 2)))
     (display " ") (display (= (h 3) (h_reduced 3)))
     (display " ") (display (= (h 4) (h_reduced 4))) (newline)

; now `(h 5)`, `(h 6)` and so on due to stack overflow of the `pow` function



;; [auxiliary]
; an iterative process
(define (h_reduced_i n)
    (define (pow x n)
        (define (iter accum counter)
            (if (> counter n) accum (iter (* x accum) (+ counter 1))))
        (iter 1 1))

    (define (iter accum counter)
        (if (= counter 0)
            accum
            (iter (pow 2 accum) (- counter 1))))

    (iter 1 n))

; iterative process with a block structure
(define (h_reduced_i_aux n)
    (define (pow x n)
        (define (iter accum counter)
            (if (> counter n) accum (iter (* x accum) (+ counter 1))))
        (iter 1 1))

    (define (iter accum counter)
        (if (= counter n)
            accum
            (iter (pow 2 accum) (+ counter 1))))

    (iter 1 0))

; iterative process with a block structure (another variant)
(define (h_reduced_i_aux2 n)
    (define (pow x n)
        (define (iter accum counter)
            (if (> counter n) accum (iter (* x accum) (+ counter 1))))
        (iter 1 1))

    (define (iter accum counter)
        (if (> counter n)
            accum
            (iter (pow 2 accum) (+ counter 1))))

    (iter 1 1))


(display (= (h_reduced 2) (h_reduced_i 2) (h_reduced_i_aux 2) (h_reduced_i_aux2 2)))
    (display " ") (display (= (h_reduced 3) (h_reduced_i 3) (h_reduced_i_aux 3) (h_reduced_i_aux2 3)))
    (display " ") (display (= (h_reduced 4) (h_reduced_i 4) (h_reduced_i_aux 4) (h_reduced_i_aux2 4))) (newline)
