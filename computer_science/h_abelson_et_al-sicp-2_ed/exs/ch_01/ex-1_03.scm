#lang sicp

; [exercise] =>
; define a procedure that takes three numbers
; as arguments and returns the sum of the squares of the two
; larger numbers


; -------------
; [solution] =>
(define (max a b) (if (> a b) a b))
(define (min a b) (if (< a b) a b))

(define (max1 a b c) (max (max a b) c))
(define (max2 a b c) (- (+ a b c) (max1 a b c) (min (min a b) c)))
          
(define (square a) (* a a))
(define (sum-of-two-max-squares a b c) (+ (square (max1 a b c)) (square (max2 a b c))))

(define assert 
    (= 5
       (sum-of-two-max-squares 0 1 2)
       (sum-of-two-max-squares 0 2 1)
       (sum-of-two-max-squares 1 0 2)
       (sum-of-two-max-squares 1 2 0)
       (sum-of-two-max-squares 2 0 1)
       (sum-of-two-max-squares 2 1 0)))
assert



;; --------------------
;; yet another solution
(define (sum-of-two-max-squares-02 param1 param2 param3)
	(define (max p1 p2) (if (> p1 p2) p1 p2))
	(define (first-max p1 p2 p3) (max (max p1 p2) p3))
	(define (square p) (* p p))
	
	(cond ((= param1 (first-max param1 param2 param3))
		      (+ (square param1) (square (max param2 param3))))
		  ((= param2 (first-max param1 param2 param3))
		      (+ (square param2) (square (max param1 param3))))
		  ((= param3 (first-max param1 param2 param3))
		      (+ (square param3) (square (max param1 param2))))))

(define assert-02
	(= 5
       (sum-of-two-max-squares-02 0 1 2)
       (sum-of-two-max-squares-02 0 2 1)
       (sum-of-two-max-squares-02 1 0 2)
       (sum-of-two-max-squares-02 1 2 0)
       (sum-of-two-max-squares-02 2 0 1)
       (sum-of-two-max-squares-02 2 1 0)))
assert-02



;; --------------------
;; yet another solution
(define (sum-of-two-max-squares-03 param1 param2 param3)
    (define (square p) (* p p))
    (define (sum-of-squares p1 p2) (+ (square p1) (square p2)))
    
    (cond
        ((and
            (>= (+ param1 param2) (+ param2 param3))
            (>= (+ param1 param2) (+ param1 param3))) (sum-of-squares param1 param2))
        ((and
            (>= (+ param1 param3) (+ param2 param3))
            (>= (+ param1 param3) (+ param1 param2))) (sum-of-squares param1 param3))
        (else (sum-of-squares param2 param3))))

(define assert-03
    (= 5
        (sum-of-two-max-squares-03 0 1 2)
        (sum-of-two-max-squares-03 0 2 1)
        (sum-of-two-max-squares-03 1 0 2)
        (sum-of-two-max-squares-03 1 2 0)
        (sum-of-two-max-squares-03 2 0 1)
        (sum-of-two-max-squares-03 2 1 0)))
assert-03



;; --------------------
;; yet another solution
(define (sum-of-two-max-squares-04 param1 param2 param3)
    (define (square p) (* p p))
    (define (min2 p1 p2) (if (< p1 p2) p1 p2))
    (define (min3 p1 p2 p3) (min2 (min2 p1 p2) p3))
    
    (- (+ (square param1) (square param2) (square param3))
       (square (min3 param1 param2 param3))))
    
(define assert-04
    (= 5
        (sum-of-two-max-squares-04 0 1 2)
        (sum-of-two-max-squares-04 0 2 1)
        (sum-of-two-max-squares-04 1 0 2)
        (sum-of-two-max-squares-04 1 2 0)
        (sum-of-two-max-squares-04 2 0 1)
        (sum-of-two-max-squares-04 2 1 0)))
assert-04



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
