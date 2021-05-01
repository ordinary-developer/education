; [exercise] =>
; define a procedure that takes three numbers
; as arguments and returns the sum of the squares of the two
; larger numbers


; -------------
; [solution] =>
(define (sum_of_largest param1 param2 param3)
    (define (square p) (* p p))
    (define maximum (max param1 param2 param3))
    (cond ((= maximum param1) (+ (square param1) (square (max param2 param3))))
          ((= maximum param2) (+ (square param2) (square (max param1 param3))))
          ((= maximum param3) (+ (square param3) (square (max param1 param2)))))        
)


(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



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
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; --------------------
;; yet another solution
(define (sum_of_largest param1 param2 param3)
    (define (square param) (* param param))
    
    (- (+ (square param1) (square param2) (square param3))    
       (square (min param1 param2 param3))))
   
   
(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
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
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
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
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
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
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
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
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; --------------------
;; yet another solution
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))
    
    (+ (sqr (max param1 param2))
       (sqr (max param3 (min param1 param2)))))
        

(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
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
                      (else (sum_of_sqrs param2 param3))))))
        

(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
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
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
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
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; ----------------
;; another solution
;; applicable only for non-negative numbers
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))
    (define (sum_of_sqrs param1 param2) (+ (sqr param1) (sqr param2)))

    (max (sum_of_sqrs param1 param2) (sum_of_sqrs param2 param3) (sum_of_sqrs param1 param3)))


(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; ----------------
;; another solution
(define (sum_of_largest param1 param2 param3)
    (+ (cond ((or (> param1 param2) (> param1 param3)) (* param1 param1)) (else 0))
       (cond ((or (> param2 param1) (> param2 param3)) (* param2 param2)) (else 0))
       (cond ((or (> param3 param1) (> param3 param2)) (* param3 param3)) (else 0)))
)


(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; ----------------
;; another solution
(define (sum_of_largest param1 param2 param3)
    (define (sum_of_sqrs param1 param2) (+ (* param1 param1) (* param2 param2)))
    
    (sum_of_sqrs (max param1 param2) (max (min param1 param2) param3)))


(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; ----------------
;; another solution
(define (sum_of_largest param1 param2 param3)
    (define first_max 
        (max (max param1 param2) param3))
    (define second_max
        (max (max (min param1 param2) (min param2 param3)) (min param1 param3)))
        
    (+ (* first_max first_max) (* second_max second_max)))
    

(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; ----------------
;; another solution
(define (sum_of_largest param1 param2 param3)
    (define (sum_of_sqrs param1 param2) (+ (* param1 param1) (* param2 param2)))
    
    (define min_three (min param1 param2 param3))
    (cond ((= min_three param1) (sum_of_sqrs param2 param3))
          ((= min_three param2) (sum_of_sqrs param1 param3))
          (else (sum_of_sqrs param1 param2))))


(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; ----------------
;; another solution
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))

    (cond ((>= param1 param2) (+ (sqr param1) (cond ((>= param2 param3) (sqr param2)) 
                                                    (else (sqr param3)))))
          (else (+ (sqr param2) (cond ((>= param1 param3) (sqr param1)) 
                                      (else (sqr param3)))))))
                                  

(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; ----------------
;; another solution
(define (sum_of_largest param1 param2 param3)
    (define (sum_of_sqrs param1 param2) (+ (* param1 param1) (* param2 param2)))
    
    (cond ((> (min param1 param2) param3) (sum_of_sqrs param1 param2))
          ((> (min param2 param3) param1) (sum_of_sqrs param2 param3))
          (else (sum_of_sqrs param1 param3))))
      

(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; ----------------
;; another solution
;; applicable only for non-negative numbers
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))
    
    (define sum1 (cond ((> param1 param2) param1)
                       ((> param1 param3) param1)
                       (else 0)))
                   
    (define sum2 (cond ((> param2 param1) param2)
                       ((> param2 param3) param2)
                       (else 0)))
                   
    (define sum3 (cond ((> param3 param1) param3)
                       ((> param3 param2) param3)
                       (else 0)))
                   
    (+ (sqr sum1) (sqr sum2) (sqr sum3)))
      

(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; ----------------
;; another solution
(define (sum_of_largest param1 param2 param3)
    (define (sum_of_sqrs param1 param2) (+ (* param1 param1) (* param2 param2)))
    
    (cond ((and (< param3 param1) (< param3 param2)) (sum_of_sqrs param1 param2))
          (else (cond ((< param2 param1) (sum_of_sqrs param1 param3))
                      (else (sum_of_sqrs param2 param3))))))


(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; ----------------
;; another solution
(define (sum_of_largest param1 param2 param3)
    (define (sum_of_sqrs param1 param2) (+ (* param1 param1) (* param2 param2)))
    
    (cond ((and (or (> param1 param2) (> param1 param3)) 
                (or (> param2 param1) (> param2 param3))) (sum_of_sqrs param1 param2))
          ((and (or (> param2 param1) (> param2 param3)) 
                (or (> param3 param1) (> param3 param2))) (sum_of_sqrs param2 param3))
          ((and (or (> param1 param2) (> param1 param3)) 
                (or (> param3 param1) (> param3 param2))) (sum_of_sqrs param1 param3))))


(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; ----------------
;; another solution
(define (sum_of_largest param1 param2 param3)
    (define (sum_of_sqrs param1 param2) (+ (* param1 param1) (* param2 param2)))

    (cond ((and (< param1 param2) (< param1 param3)) (sum_of_sqrs param2 param3))
          ((and (< param2 param1) (< param2 param3)) (sum_of_sqrs param1 param3))    
          ((and (< param3 param2) (< param3 param1)) (sum_of_sqrs param1 param2))))


(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; another solution
;; ----------------
(define (sum_of_largest param1 param2 param3)
    (define (sqr param) (* param param))
    (define (first_is_max param1 param2 param3) (cond ((< param1 param2 param3) 0) (else param1)))

    (+ (sqr (first_is_max param1 param2 param3))
       (sqr (first_is_max param2 param1 param3))
       (sqr (first_is_max param3 param1 param2)))
)


(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)



;; another solution
;; ----------------
(define (sum_of_largest param1 param2 param3)
    (define (sum_of_sqrs param1 param2) (+ (* param1 param1) (* param2 param2)))
    (cond ((> param1 param2) (cond ((> param2 param3) (sum_of_sqrs param1 param2)) 
                                   (else (sum_of_sqrs param1 param3))))
          (else (cond ((< param1 param3) (sum_of_sqrs param2 param3)) (else (sum_of_sqrs param1 param2))))))


(define ret (=
    5
    (sum_of_largest 0 1 2)
    (sum_of_largest 0 2 1)
    (sum_of_largest 1 0 2)
    (sum_of_largest 1 2 0)
    (sum_of_largest 2 0 1)
    (sum_of_largest 2 1 0)))
(display ret) (newline)
