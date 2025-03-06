#lang sicp

; [exercise] =>
; define a procedure that takes three numbers
; as arguments and returns the sum of the squares of the two
; larger numbers



; [solution] =>
;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-02 param1 param2 param3)
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
       (sum-of-squares-of-two-max-02 0 1 2)
       (sum-of-squares-of-two-max-02 0 2 1)
       (sum-of-squares-of-two-max-02 1 0 2)
       (sum-of-squares-of-two-max-02 1 2 0)
       (sum-of-squares-of-two-max-02 2 0 1)
       (sum-of-squares-of-two-max-02 2 1 0)))
assert-02



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-03 param1 param2 param3)
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
        (sum-of-squares-of-two-max-03 0 1 2)
        (sum-of-squares-of-two-max-03 0 2 1)
        (sum-of-squares-of-two-max-03 1 0 2)
        (sum-of-squares-of-two-max-03 1 2 0)
        (sum-of-squares-of-two-max-03 2 0 1)
        (sum-of-squares-of-two-max-03 2 1 0)))
assert-03
    
    
    
;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-04 param1 param2 param3)
    (define (square p) (* p p))
    (define (min2 p1 p2) (if (< p1 p2) p1 p2))
    (define (min3 p1 p2 p3) (min2 (min2 p1 p2) p3))
    
    (- (+ (square param1) (square param2) (square param3))
       (square (min3 param1 param2 param3))))
    
(define assert-04
    (= 5
        (sum-of-squares-of-two-max-04 0 1 2)
        (sum-of-squares-of-two-max-04 0 2 1)
        (sum-of-squares-of-two-max-04 1 0 2)
        (sum-of-squares-of-two-max-04 1 2 0)
        (sum-of-squares-of-two-max-04 2 0 1)
        (sum-of-squares-of-two-max-04 2 1 0)))
assert-04



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-05 param1 param2 param3)
    (define (square p) (* p p))
    (define (sum-of-squares p1 p2) (+ (square p1) (square p2)))
    
    (cond
        ((not (or (> param1 param2) (> param1 param3))) (sum-of-squares param2 param3))
        (else (sum-of-squares-of-two-max-05 param2 param3 param1))))

(define assert-05
    (= 5
        (sum-of-squares-of-two-max-05 0 1 2)
        (sum-of-squares-of-two-max-05 0 2 1)
        (sum-of-squares-of-two-max-05 1 0 2)
        (sum-of-squares-of-two-max-05 1 2 0)
        (sum-of-squares-of-two-max-05 2 0 1)
        (sum-of-squares-of-two-max-05 2 1 0)))
assert-05



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-06 param1 param2 param3)
    (define (min2 p1 p2) (if (< p1 p2) p1 p2))
    (define (min3 p1 p2 p3) (min2 (min2 p1 p2) p3))    
    (define (square p) (* p p))
    (define (sum-of-squares p1 p2) (+ (square p1) (square p2)))
    
    (cond
        ((= param1 (min3 param1 param2 param3)) (sum-of-squares param2 param3))
        (else (sum-of-squares-of-two-max-06 param2 param3 param1))))
    
(define assert-06
    (= 5
        (sum-of-squares-of-two-max-06 0 1 2)
        (sum-of-squares-of-two-max-06 0 2 1)
        (sum-of-squares-of-two-max-06 1 0 2)
        (sum-of-squares-of-two-max-06 1 2 0)
        (sum-of-squares-of-two-max-06 2 0 1)
        (sum-of-squares-of-two-max-06 2 1 0)))
assert-06    



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-07 param1 param2 param3)
    (define (square p) (* p p))
    (define (sum-of-squares p1 p2) (+ (square p1) (square p2)))
    
    (cond
        ((and (<= param1 param2) (<= param1 param3)) (sum-of-squares param2 param3))
        ((and (<= param2 param1) (<= param2 param3)) (sum-of-squares param1 param3))
        (else (sum-of-squares param1 param2))))
    
(define assert-07
    (= 5
        (sum-of-squares-of-two-max-07 0 1 2)
        (sum-of-squares-of-two-max-07 0 2 1)
        (sum-of-squares-of-two-max-07 1 0 2)
        (sum-of-squares-of-two-max-07 1 2 0)
        (sum-of-squares-of-two-max-07 2 0 1)
        (sum-of-squares-of-two-max-07 2 1 0)))
assert-07



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-08 param1 param2 param3)
    (define (max2 p1 p2) (if (> p1 p2) p1 p2))
    (define (square p) (* p p))
    (define (sum-of-squares p1 p2) (+ (square p1) (square p2)))

    (cond 
        ((and (> param1 param2) (> param1 param3)) (sum-of-squares param1 (max2 param2 param3)))
        ((and (> param2 param3) (> param2 param3)) (sum-of-squares param2 (max2 param1 param3)))
        (else (sum-of-squares param3 (max2 param1 param2)))))

(define assert-08
    (= 5
       (sum-of-squares-of-two-max-08 0 1 2)
       (sum-of-squares-of-two-max-08 0 2 1)
       (sum-of-squares-of-two-max-08 1 0 2)
       (sum-of-squares-of-two-max-08 1 2 0)
       (sum-of-squares-of-two-max-08 2 0 1)
       (sum-of-squares-of-two-max-08 2 1 0)))
assert-08 



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-09 param1 param2 param3)
    (define (min2 p1 p2) (if (< p1 p2) p1 p2))
    (define (max2 p1 p2) (if (> p1 p2) p1 p2))    
    (define (square p) (* p p))

    (+ (square (max2 param1 param2))
       (square (max2 param3 (min2 param1 param2)))))

(define assert-09
    (= 5
       (sum-of-squares-of-two-max-09 0 1 2)
       (sum-of-squares-of-two-max-09 0 2 1)
       (sum-of-squares-of-two-max-09 1 0 2)
       (sum-of-squares-of-two-max-09 1 2 0)
       (sum-of-squares-of-two-max-09 2 0 1)
       (sum-of-squares-of-two-max-09 2 1 0)))
assert-09



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-10  param1 param2 param3)
    (define (square p) (* p p))
    (define (sum-of-squares p1 p2) (+ (square p1) (square p2)))

    (cond ((> param1 param2)
           (cond ((> param2 param3) (sum-of-squares param1 param2))
                 (else (sum-of-squares param1 param3))))
          (else (cond ((> param1 param3) (sum-of-squares param1 param2))
                      (else (sum-of-squares param2 param3))))))

(define assert-10
    (= 5
       (sum-of-squares-of-two-max-10 0 1 2)
       (sum-of-squares-of-two-max-10 0 2 1)
       (sum-of-squares-of-two-max-10 1 0 2)
       (sum-of-squares-of-two-max-10 1 2 0)
       (sum-of-squares-of-two-max-10 2 0 1)
       (sum-of-squares-of-two-max-10 2 1 0)))
assert-10



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-11 param1 param2 param3)
    (define (square p) (* p p))
    (define (sum-of-squares p1 p2) (+ (square p1) (square p2)))
    
    (cond
        ((and (>= param1 param3) (>= param2 param3)) (sum-of-squares param1 param2))
        ((and (>= param1 param2) (>= param3 param2)) (sum-of-squares param1 param3))
        (else (sum-of-squares param2 param3))))

(define assert-11
    (= 5
       (sum-of-squares-of-two-max-11 0 1 2)
       (sum-of-squares-of-two-max-11 0 2 1)
       (sum-of-squares-of-two-max-11 1 0 2)
       (sum-of-squares-of-two-max-11 1 2 0)
       (sum-of-squares-of-two-max-11 2 0 1)
       (sum-of-squares-of-two-max-11 2 1 0)))
assert-11



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-12 param1 param2 param3)
    (define (max2 p1 p2) (if (> p1 p2) p1 p2))
    (define (square p) (* p p))
    (define (sum-of-squares p1 p2) (+ (square p1) (square p2)))

    (cond
        ((< param1 param2) (sum-of-squares param2 (max2 param1 param3)))
        (else (sum-of-squares param1 (max2 param2 param3)))))

(define assert-12
    (= 5
       (sum-of-squares-of-two-max-12 0 1 2)
       (sum-of-squares-of-two-max-12 0 2 1)
       (sum-of-squares-of-two-max-12 1 0 2)
       (sum-of-squares-of-two-max-12 1 2 0)
       (sum-of-squares-of-two-max-12 2 0 1)
       (sum-of-squares-of-two-max-12 2 1 0)))
assert-12



;; --------------------
;; yet another solution
;; applicable only for non-negative numbers
(define (sum-of-squares-of-two-max-13 param1 param2 param3)
    (define (max2 p1 p2) (if (> p1 p2) p1 p2))
    (define (max3 p1 p2 p3) (max2 (max2 p1 p2) p3))
    (define (square p) (* p p))
    (define (sum-of-squares p1 p2) (+ (square p1) (square p2)))

    (max3 (sum-of-squares param1 param2) (sum-of-squares param2 param3) (sum-of-squares param1 param3)))

(define assert-13
    (= 5
       (sum-of-squares-of-two-max-13 0 1 2)
       (sum-of-squares-of-two-max-13 0 2 1)
       (sum-of-squares-of-two-max-13 1 0 2)
       (sum-of-squares-of-two-max-13 1 2 0)
       (sum-of-squares-of-two-max-13 2 0 1)
       (sum-of-squares-of-two-max-13 2 1 0)))
assert-13



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-14 param1 param2 param3)
    (+ (cond ((or (> param1 param2) (> param1 param3)) (* param1 param1)) (else 0))
       (cond ((or (> param2 param1) (> param2 param3)) (* param2 param2)) (else 0))
       (cond ((or (> param3 param1) (> param3 param2)) (* param3 param3)) (else 0))))

(define assert-14
    (= 5
       (sum-of-squares-of-two-max-14 0 1 2)
       (sum-of-squares-of-two-max-14 0 2 1)
       (sum-of-squares-of-two-max-14 1 0 2)
       (sum-of-squares-of-two-max-14 1 2 0)
       (sum-of-squares-of-two-max-14 2 0 1)
       (sum-of-squares-of-two-max-14 2 1 0)))
assert-14



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-15 param1 param2 param3)
    (define (min2 p1 p2) (if (< p1 p2) p1 p2))
    (define (max2 p1 p2) (if (> p1 p2) p1 p2))
    (define (sum-of-squares p1 p2) (+ (* p1 p1) (* p2 p2)))
    
    (sum-of-squares (max2 param1 param2) (max2 (min2 param1 param2) param3)))

(define assert-15
    (= 5
       (sum-of-squares-of-two-max-15 0 1 2)
       (sum-of-squares-of-two-max-15 0 2 1)
       (sum-of-squares-of-two-max-15 1 0 2)
       (sum-of-squares-of-two-max-15 1 2 0)
       (sum-of-squares-of-two-max-15 2 0 1)
       (sum-of-squares-of-two-max-15 2 1 0)))
assert-15



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-16 param1 param2 param3)
    (define (min2 p1 p2) (if (< p1 p2) p1 p2))
    (define (max2 p1 p2) (if (> p1 p2) p1 p2))
    
    (define (first-max p1 p2 p3)
        (max2 (max2 p1 p2) p3))
    (define (second-max p1 p2 p3)
        (max2 (max2 (min2 p1 p2) (min2 p2 p3))
              (min2 p1 p3)))
              
   (+ (* (first-max param1 param2 param3) (first-max param1 param2 param3))
      (* (second-max param1 param2 param3) (second-max param1 param2 param3))))

(define assert-16
    (= 5
       (sum-of-squares-of-two-max-16 0 1 2)
       (sum-of-squares-of-two-max-16 0 2 1)
       (sum-of-squares-of-two-max-16 1 0 2)
       (sum-of-squares-of-two-max-16 1 2 0)
       (sum-of-squares-of-two-max-16 2 0 1)
       (sum-of-squares-of-two-max-16 2 1 0)))
assert-16



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-17 param1 param2 param3)
    (define (sum-of-squares p1 p2) (+ (* p1 p1) (* p2 p2)))
    (define (min2 p1 p2) (if (< p1 p2) p1 p2))
    (define (min3 p1 p2 p3) (min2 (min2 p1 p2) p3))

    (cond ((= (min3 param1 param2 param3) param1) (sum-of-squares param2 param3))
          ((= (min3 param1 param2 param3) param2) (sum-of-squares param1 param3))
          (else (sum-of-squares param1 param2))))

(define assert-17
    (= 5
       (sum-of-squares-of-two-max-17 0 1 2)
       (sum-of-squares-of-two-max-17 0 2 1)
       (sum-of-squares-of-two-max-17 1 0 2)
       (sum-of-squares-of-two-max-17 1 2 0)
       (sum-of-squares-of-two-max-17 2 0 1)
       (sum-of-squares-of-two-max-17 2 1 0)))
assert-17



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-18 param1 param2 param3)
    (define (square p) (* p p))

    (cond ((>= param1 param2) (+ (square param1) (cond ((>= param2 param3) (square param2))
                                                       (else (square param3)))))
          (else (+ (square param2)
                   (cond ((>= param1 param3) (square param1))
                         (else (square param3)))))))

(define assert-18
    (= 5
       (sum-of-squares-of-two-max-18 0 1 2)
       (sum-of-squares-of-two-max-18 0 2 1)
       (sum-of-squares-of-two-max-18 1 0 2)
       (sum-of-squares-of-two-max-18 1 2 0)
       (sum-of-squares-of-two-max-18 2 0 1)
       (sum-of-squares-of-two-max-18 2 1 0)))
assert-18



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-19 param1 param2 param3)
    (define (square p) (* p p))

    (cond ((>= param1 param2) (+ (square param1)
                                 (square (if (> param2 param3) param2 param3))))
          (else (+ (square param2)
                   (square (if (> param1 param3) param1 param3))))))

(define assert-19
    (= 5
       (sum-of-squares-of-two-max-19 0 1 2)
       (sum-of-squares-of-two-max-19 0 2 1)
       (sum-of-squares-of-two-max-19 1 0 2)
       (sum-of-squares-of-two-max-19 1 2 0)
       (sum-of-squares-of-two-max-19 2 0 1)
       (sum-of-squares-of-two-max-19 2 1 0)))
assert-19



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-20 param1 param2 param3)
    (define (min2 p1 p2) (if (< p1 p2) p1 p2))
    (define (sum-of-squares p1  p2) (+ (* p1 p1) (* p2 p2)))

    (cond ((> (min2 param1 param2) param3) (sum-of-squares param1 param2))
          ((> (min2 param2 param3) param1) (sum-of-squares param2 param3))
          (else (sum-of-squares param1 param3))))

(define assert-20
    (= 5
       (sum-of-squares-of-two-max-20 0 1 2)
       (sum-of-squares-of-two-max-20 0 2 1)
       (sum-of-squares-of-two-max-20 1 0 2)
       (sum-of-squares-of-two-max-20 1 2 0)
       (sum-of-squares-of-two-max-20 2 0 1)
       (sum-of-squares-of-two-max-20 2 1 0)))
assert-20



;; --------------------
;; yet another solution
;; applicable only for non-negative numbers
(define (sum-of-squares-of-two-max-21 param1 param2 param3)
    (define sum1 (cond ((> param1 param2) param1)
                       ((> param1 param3) param1)
                       (else 0)))

    (define sum2 (cond ((> param2 param1) param2)
                       ((> param2 param3) param2)
                       (else 0)))

    (define sum3 (cond ((> param3 param1) param3)
                       ((> param3 param2) param3)
                       (else 0)))

    (define (square p) (* p p))

    (+ (square sum1) (square sum2) (square sum3)))

(define assert-21
    (= 5
       (sum-of-squares-of-two-max-21 0 1 2)
       (sum-of-squares-of-two-max-21 0 2 1)
       (sum-of-squares-of-two-max-21 1 0 2)
       (sum-of-squares-of-two-max-21 1 2 0)
       (sum-of-squares-of-two-max-21 2 0 1)
       (sum-of-squares-of-two-max-21 2 1 0)))
assert-21



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-22 param1 param2 param3)
    (define (sum-of-squares p1 p2) (+ (* p1 p1) (* p2 p2)))

    (cond ((and (< param3 param1) (< param3 param2)) (sum-of-squares param1 param2))
          (else (cond ((< param2 param1) (sum-of-squares param1 param3))
                      (else (sum-of-squares param2 param3))))))

(define assert-22
    (= 5
       (sum-of-squares-of-two-max-22 0 1 2)
       (sum-of-squares-of-two-max-22 0 2 1)
       (sum-of-squares-of-two-max-22 1 0 2)
       (sum-of-squares-of-two-max-22 1 2 0)
       (sum-of-squares-of-two-max-22 2 0 1)
       (sum-of-squares-of-two-max-22 2 1 0)))
assert-22



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-23 param1 param2 param3)
    (define (sum-of-squares p1 p2) (+ (* p1 p1) (* p2 p2)))

    (cond ((and (or (> param1 param2) (> param1 param3))
                (or (> param2 param1) (> param2 param3))) (sum-of-squares param1 param2))
          ((and (or (> param2 param1) (> param2 param3))
                (or (> param3 param1) (> param3 param2))) (sum-of-squares param2 param3))
          ((and (or (> param1 param2) (> param1 param3))
                (or (> param3 param1) (> param3 param2))) (sum-of-squares param1 param3))))

(define assert-23
    (= 5
       (sum-of-squares-of-two-max-23 0 1 2)
       (sum-of-squares-of-two-max-23 0 2 1)
       (sum-of-squares-of-two-max-23 1 0 2)
       (sum-of-squares-of-two-max-23 1 2 0)
       (sum-of-squares-of-two-max-23 2 0 1)
       (sum-of-squares-of-two-max-23 2 1 0)))
assert-23



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-24 param1 param2 param3)
    (define (sum-of-squares p1 p2) (+ (* p1 p1) (* p2 p2)))

    (cond ((and (< param1 param2) (< param1 param3)) (sum-of-squares param2 param3))
          ((and (< param2 param1) (< param2 param3)) (sum-of-squares param1 param3))
          ((and (< param3 param2) (< param3 param1)) (sum-of-squares param1 param2))))

(define assert-24
    (= 5
       (sum-of-squares-of-two-max-24 0 1 2)
       (sum-of-squares-of-two-max-24 0 2 1)
       (sum-of-squares-of-two-max-24 1 0 2)
       (sum-of-squares-of-two-max-24 1 2 0)
       (sum-of-squares-of-two-max-24 2 0 1)
       (sum-of-squares-of-two-max-24 2 1 0)))
assert-24



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-25 param1 param2 param3)
    (define (square p) (* p p))
    (define (first-if-max-or-zero p1 p2 p3) (cond ((and (< p1 p2) (< p1 p3)) 0) (else p1)))

    (+ (square (first-if-max-or-zero param1 param2 param3))
       (square (first-if-max-or-zero param2 param1 param3))
       (square (first-if-max-or-zero param3 param1 param2))))

(define assert-25
    (= 5
       (sum-of-squares-of-two-max-25 0 1 2)
       (sum-of-squares-of-two-max-25 0 2 1)
       (sum-of-squares-of-two-max-25 1 0 2)
       (sum-of-squares-of-two-max-25 1 2 0)
       (sum-of-squares-of-two-max-25 2 0 1)
       (sum-of-squares-of-two-max-25 2 1 0)))
assert-25



;; --------------------
;; yet another solution
(define (sum-of-squares-of-two-max-26 param1 param2 param3)
    (define (sum-of-squares p1 p2) (+ (* p1 p1) (* p2 p2)))
    (cond ((> param1 param2) (cond ((> param2 param3) (sum-of-squares param1 param2))
                                   (else (sum-of-squares param1 param3))))
           (else (cond ((< param1 param3) (sum-of-squares param2 param3))
                       (else (sum-of-squares param1 param2))))))
    
(define assert-26
    (= 5
       (sum-of-squares-of-two-max-26 0 1 2)
       (sum-of-squares-of-two-max-26 0 2 1)
       (sum-of-squares-of-two-max-26 1 0 2)
       (sum-of-squares-of-two-max-26 1 2 0)
       (sum-of-squares-of-two-max-26 2 0 1)
       (sum-of-squares-of-two-max-26 2 1 0)))
assert-26
