;; [exercise]
; Newton's method for cube roots is based on the fact
; that if `y` is an approximation to the cube root of `x`,
; then a better approximation is given by the value
;
;  (x/y^2 + 2y) / 3
; 
; Use thise formula to implement a cube-root procedure
; analogous to the square-root procedure



;; [solution]
(define (cube_root x)    
    (define (cube_root_iter guess)
        (if (good_enough? guess)
            guess
            (cube_root_iter (improve guess))))

    (define (good_enough? guess) (< (abs (- (cube guess) x)) 0.001))
    (define (cube num) (* num num num))
    (define (improve guess)
        (/ (+ (/ x (square guess)) (* 2 guess)) 3))
    (define (square num) (* num num))

    (cube_root_iter 1.0 x))

(define (are_equal_f num1 num2) (< (abs (- num1 num2)) 0.001))


; test
(define (OUTPUT_TEST name ret)
    (if ret
        (display "[  OK  ]")
        (display "[FAILED]"))
    (display " ") (display name) (newline))


(display "running tests") (newline)

(define require (and 
    (are_equal_f 2 (cube_root 8))
    (are_equal_f 3 (cube_root 27))
    (are_equal_f 4 (cube_root 64))))
(OUTPUT_TEST "cube_root with integer numbers" require)

(define require (and 
    (are_equal_f 2.5 (cube_root 15.625))
    (are_equal_f 3.7 (cube_root 50.653))
    (are_equal_f 4.9 (cube_root 117.649))))
(OUTPUT_TEST "cube_root with real numbers" require)    

(define require (and 
    (are_equal_f (- 2) (cube_root (- 8)))
    (are_equal_f (- 2.5) (cube_root (- 15.625)))
(OUTPUT_TEST "cube_root with negative numbers" require)    
