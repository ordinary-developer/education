;; define a procedure that takes three numbers
;; as arguments and returns the sum of the squares of the two
;; larger numbers

(define (func param1 param2 param3)
    (define (square p) (* p p))
    (define maximum (max param1 param2 param3))
    (cond ((= maximum param1) (+ (square param1) (square (max param2 param3))))
          ((= maximum param2) (+ (square param2) (square (max param1 param3))))
          ((= maximum param3) (+ (square param3) (square (max param1 param2)))))        
)

(display (func 1 2 3)) (newline)
(display (func 3 2 1)) (newline)
(display (func (- 1) (- 2) (- 3))) (newline)
(display (func (- 3) (- 2) (- 1))) (newline)
(display (func 0.1 0.2 0.3)) (newline)
(display (func (- 0.1) (- 0.2) (- 0.3))) (newline)



;; --------------------
;; yet another solution
(define (sum_of_largest param1 param2 param3)
    (define (square param) (* param param))
    (define (square_sum param1 param2) (+ (square param1) (square param2)))
    
    (cond
        ((and 
            (>= (+ param1 param2) (+ param2 param3)) 
            (>= (+ param1 param2) (+ param1 param3))) (square_sum param1 param2))
        ((and 
            (>= (+ param1 param3) (+ param2 param3))
            (>= (+ param1 param3) (+ param1 param2))) (square_sum param1 param3))
        (else (square_sum param2 param3))))


(define ret (=
    13 
    (sum_of_largest 1 2 3)
    (sum_of_largest 1 3 2)
    (sum_of_largest 2 1 3)
    (sum_of_largest 2 3 1)
    (sum_of_largest 3 1 2)
    (sum_of_largest 3 2 1)))
(display ret) (newline)



;; --------------------
;; yet another solution
(define (sum_of_largest param1 param2 param3)
    (define (square param) (* param param))
    
    (- (+ (square param1) (square param2) (square param3))    
       (square (min param1 param2 param3))))
   
   
(define ret (= 
    13
    (sum_of_largest 1 2 3)
    (sum_of_largest 1 3 2)
    (sum_of_largest 2 1 3)
    (sum_of_largest 2 3 1)
    (sum_of_largest 3 1 2)
    (sum_of_largest 3 2 1)))
(display ret) (newline)



;; --------------------
;; yet another solution
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param)) 
    (define (sum_sqr param1 param2) (+ (sqr param1) (sqr param2)))
    
    (cond
       ((not (or (> param1 param2) (> param1 param3))) (sum_sqr param2 param3)) 
       (else (sum_of_largest param2 param3 param1))))


(define ret (= 
    13
    (sum_of_largest 1 2 3)
    (sum_of_largest 1 3 2)
    (sum_of_largest 2 1 3)
    (sum_of_largest 2 3 1)
    (sum_of_largest 3 1 2)
    (sum_of_largest 3 2 1)))
(display ret) (newline)



;; --------------------
;; yet another solution
(define (sum_of_largest param1 param2 param3) 
    (define (sqr param) (* param param))
    (define (sum_sqr param1 param2) (+ (sqr param1) (sqr param2)))
    
    (cond
        ((= param1 (min param1 param2 param3)) (sum_sqr param2 param3))
        (else (sum_of_largest param2 param3 param1))))
    
    
(define ret (= 
    13
    (sum_of_largest 1 2 3)
    (sum_of_largest 1 3 2)
    (sum_of_largest 2 1 3)
    (sum_of_largest 2 3 1)
    (sum_of_largest 3 1 2)
    (sum_of_largest 3 2 1)))
(display ret) (newline)



;; --------------------
;; yet another solution
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))
    (define (sum_sqr param1 param2) (+ (sqr param1) (sqr param2)))
    
    (cond
        ((and (<= param1 param2) (<= param1 param3)) (sum_sqr param2 param3))
        ((and (<= param2 param1) (<= param2 param3)) (sum_sqr param1 param3)) 
        (else (sum_sqr param1 param2))))


(define ret (= 
    13
    (sum_of_largest 1 2 3)
    (sum_of_largest 1 3 2)
    (sum_of_largest 2 1 3)
    (sum_of_largest 2 3 1)
    (sum_of_largest 3 1 2)
    (sum_of_largest 3 2 1)))
(display ret) (newline)



;; --------------------
;; yet another solution
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))
    (define (sum_of_sqrs param1 param2) (+ (sqr param1) (sqr param2)))
    
    (cond
        ((and (> param1 param2) (> param1 param3)) (sum_of_sqrs param1 (max param2 param3)))     
        ((and (> param2 param1) (> param2 param3)) (sum_of_sqrs param2 (max param1 param3)))
        (else (sum_of_sqrs param3 (max param1 param2)))))
        

(define ret (= 
    13
    (sum_of_largest 1 2 3)
    (sum_of_largest 1 3 2)
    (sum_of_largest 2 1 3)
    (sum_of_largest 2 3 1)
    (sum_of_largest 3 1 2)
    (sum_of_largest 3 2 1)))
(display ret) (newline)



;; --------------------
;; yet another solution
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))
    
    (+ (sqr (max param1 param2))
       (sqr (max param3 (min param1 param2)))))
        

(define ret (= 
    13
    (sum_of_largest 1 2 3)
    (sum_of_largest 1 3 2)
    (sum_of_largest 2 1 3)
    (sum_of_largest 2 3 1)
    (sum_of_largest 3 1 2)
    (sum_of_largest 3 2 1)))
(display ret) (newline)



;; -----------------
yet another solution
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))
    (define (sum_of_sqrs param1 param2) (+ (sqr param1) (sqr param2)))
    
    (cond ((> param1 param2)
          (cond ((> param2 param3) (sum_of_sqrs param1 param2)) 
                (else (sum_of_sqrs param1 param3))))
          (else (cond ((> param1 param3) (sum_of_sqrs param1 param2)) 
                      (else (sum_of_sqrs param2 param3)))))
)
        

(define ret (= 
    13
    (sum_of_largest 1 2 3)
    (sum_of_largest 1 3 2)
    (sum_of_largest 2 1 3)
    (sum_of_largest 2 3 1)
    (sum_of_largest 3 1 2)
    (sum_of_largest 3 2 1)))
(display ret) (newline)
   


;; ----------------
;; another solution
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))
    (define (sum_of_sqrs param1 param2) (+ (sqr param1) (sqr param2)))
    
    (cond 
         ((and (>= param1 param3)(>= param2 param3)) (sum_of_sqrs param1 param2))
         ((and (>= param1 param2)(>= param3 param2)) (sum_of_sqrs param1 param3))
         (else (sum_of_sqrs param2 param3))))


(define ret (=
    13 
    (sum_of_largest 1 2 3)
    (sum_of_largest 1 3 2)
    (sum_of_largest 2 1 3)
    (sum_of_largest 2 3 1)
    (sum_of_largest 3 1 2)
    (sum_of_largest 3 2 1)))
(display ret) (newline)


;; ----------------
;; another solution
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))
    (define (sum_of_sqrs param1 param2) (+ (sqr param1) (sqr param2)))
    
    (cond
        ((< param1 param2) (sum_of_sqrs param2 (max param1 param3)))
        (else (sum_of_sqrs param1 (max param2 param3)))))


(define ret (=
    13 
    (sum_of_largest 1 2 3)
    (sum_of_largest 1 3 2)
    (sum_of_largest 2 1 3)
    (sum_of_largest 2 3 1)
    (sum_of_largest 3 1 2)
    (sum_of_largest 3 2 1)))
(display ret) (newline)



;; ----------------
;; another solution
;; applicable only for non-negative numbers
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))
    (define (sum_of_sqrs param1 param2) (+ (sqr param1) (sqr param2)))

    (max (sum_of_sqrs param1 param2) (sum_of_sqrs param2 param3) (sum_of_sqrs param1 param3)))



(define ret (=
    13 
    (sum_of_largest 1 2 3)
    (sum_of_largest 1 3 2)
    (sum_of_largest 2 1 3)
    (sum_of_largest 2 3 1)
    (sum_of_largest 3 1 2)
    (sum_of_largest 3 2 1)))
(display ret) (newline)