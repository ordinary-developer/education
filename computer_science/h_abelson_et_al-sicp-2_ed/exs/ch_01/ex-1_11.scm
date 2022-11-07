;; [exercise]
; A function `f` is defined by the rule that
;          _
;         | n if n < 3,
; f(n) = <
;         | f(n - 1) + 2f(n - 2) + 3f(n - 3) if n >= 3.
;          _
; Write a procedures that computes `f`
; by means of a recursive process.
; Write a procedure that computes `f`
; by means of an iterative process.


;; [solution]
;; # recursive process
(define (f_r n)
    (if (< n 3) 
        n
        (+ (f_r (- n 1))
           (* 2 (f_r (- n 2))) 
           (* 3 (f_r (- n 3))))))

;; # iterative process
(define (f_i n)
    (define (iter a b c counter)
        (if (= counter 0)
            c
            (iter (+ a (* 2 b) (* 3 c)) a b (- counter 1))))
    
    (iter 2 1 0 n))

;; # iterative process with a block structure
(define (f_i_aux n)
    (define (iter a b c counter)
        (if (> counter n)
            c
            (iter (+ a (* 2 b) (* 3 c)) a b (+ counter 1))))
    
    (iter 2 1 0 1))

(display (= (f_r 1) (f_i 1) (f_i_aux 1)))
    (display " ") (display (= (f_r 2) (f_i 2) (f_i_aux 2)))
    (display " ") (display (= (f_r 3) (f_i 3) (f_i_aux 3)))
    (display " ") (display (= (f_r 4) (f_i 4) (f_i_aux 4)))
    (display " ") (display (= (f_r 5) (f_i 5) (f_i_aux 5)))
    (display " ") (display (= (f_r 7) (f_i 7) (f_i_aux 7)))
    (display " ") (display (= (f_r 10) (f_i 10) (f_i_aux 10)))
    (display " ") (display (= (f_r 15) (f_i 15) (f_i_aux 15))) (newline)
