; [exercise] =>
; translate the following expression into prefix form:
;
; 5 + 4 + (2 - (3 - (6 + 4/5)))
; ----------------------------
;       3(6 - 2)(2 - 7)
;


; -------------
; [solution] =>
(define result 
    (/ (+ 5 4 (- 2 (- 3 (+ 6 (/ 4 5)))))
       (* 3 (- 6 2) (- 2 7)))
)

(display result) (newline)
