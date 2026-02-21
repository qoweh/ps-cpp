# MySQL 코딩테스트 핸드북

> Oracle 경험자를 위한 MySQL 문법 정리. SW마에스트로 코딩테스트 대비용.

---

## 목차
1. [쿼리 실행 순서](#1-쿼리-실행-순서)
2. [SELECT / FROM / WHERE](#2-select--from--where)
3. [비교·논리 연산자](#3-비교논리-연산자)
4. [BETWEEN, IN, LIKE, REGEXP](#4-between-in-like-regexp)
5. [NULL 처리](#5-null-처리)
6. [정렬 (ORDER BY)](#6-정렬-order-by)
7. [집계 함수 & GROUP BY & HAVING](#7-집계-함수--group-by--having)
8. [JOIN](#8-join)
9. [서브쿼리](#9-서브쿼리)
10. [집합 연산 (UNION 등)](#10-집합-연산)
11. [윈도우 함수](#11-윈도우-함수)
12. [CTE (WITH)](#12-cte-with)
13. [CASE WHEN](#13-case-when)
14. [문자열 함수](#14-문자열-함수)
15. [숫자 함수](#15-숫자-함수)
16. [날짜·시간 함수](#16-날짜시간-함수)
17. [형변환 (CAST / CONVERT)](#17-형변환)
18. [LIMIT & OFFSET](#18-limit--offset)
19. [변수](#19-변수)
20. [기타 자주 쓰이는 함수](#20-기타-자주-쓰이는-함수)

---

## 1. 쿼리 실행 순서

```
FROM → WHERE → GROUP BY → 집계함수 → HAVING → SELECT → ORDER BY → LIMIT
```

> WHERE에서는 별칭(alias)·윈도우 함수 사용 불가. HAVING에서는 집계 함수 사용 가능.

---

## 2. SELECT / FROM / WHERE

```sql
-- 기본 조회
SELECT id, name FROM employees WHERE salary > 50000;

-- 모든 컬럼
SELECT * FROM employees;

-- 중복 제거
SELECT DISTINCT dept FROM employees;

-- 별칭
SELECT name AS 이름, salary * 12 AS 연봉 FROM employees;
```

---

## 3. 비교·논리 연산자

| 연산자 | 설명 |
|--------|------|
| `=` | 같다 (Oracle의 `=`과 동일) |
| `<>` 또는 `!=` | 다르다 |
| `<`, `<=`, `>`, `>=` | 비교 |
| `AND`, `OR`, `NOT` | 논리 |

```sql
SELECT name FROM instructor
WHERE dept_name = 'CS' AND salary > 80000;
```

> **Oracle과 차이**: MySQL은 `!=`도 지원. Oracle은 `<>`만 표준.

---

## 4. BETWEEN, IN, LIKE, REGEXP

### BETWEEN
```sql
-- A 이상 B 이하 (양끝 포함)
SELECT * FROM orders
WHERE order_date BETWEEN '2025-01-01' AND '2025-01-31';

-- 주의: 날짜는 '2025-01-31' = '2025-01-31 00:00:00'
-- 시분초 데이터가 있다면 '2025-02-01' 미만으로 처리하는 게 안전
```

### IN
```sql
SELECT * FROM employees WHERE dept IN ('HR', 'IT', 'Sales');

-- 서브쿼리와 함께
SELECT * FROM employees
WHERE dept_id IN (SELECT id FROM departments WHERE location = 'Seoul');
```

### NOT IN
```sql
SELECT * FROM employees WHERE dept NOT IN ('HR', 'IT');
```

> **주의**: `NOT IN`에 NULL이 포함되면 결과가 항상 빈 집합. NULL 가능성이 있으면 `NOT EXISTS` 사용.

### LIKE (패턴 매칭)
```sql
-- %: 0개 이상 임의 문자, _: 정확히 1개 문자
SELECT * FROM employees WHERE name LIKE '김%';      -- '김'으로 시작
SELECT * FROM employees WHERE name LIKE '%수';      -- '수'로 끝남
SELECT * FROM employees WHERE name LIKE '%민%';     -- '민' 포함
SELECT * FROM employees WHERE name LIKE '김__';     -- '김' + 2글자
SELECT * FROM employees WHERE name NOT LIKE '%test%';

-- 주소 검색 팁: '서울%' 사용 (서울시/서울특별시 모두 매칭)
```

### REGEXP (정규식)
```sql
SELECT * FROM employees WHERE name REGEXP '^김';       -- '김'으로 시작
SELECT * FROM employees WHERE name REGEXP '수$';       -- '수'로 끝남
SELECT * FROM employees WHERE email REGEXP '^[a-z]+@'; -- 소문자로 시작하는 이메일
SELECT * FROM employees WHERE name REGEXP '김|이|박';  -- 김 또는 이 또는 박 포함
```

---

## 5. NULL 처리

- `NULL`은 값이 없음/알 수 없음
- `NULL = NULL` → NULL (TRUE가 아님!)
- 산술 연산에 NULL 포함 시 결과도 NULL

```sql
-- NULL 확인 (= 으로 비교 불가!)
SELECT * FROM employees WHERE phone IS NULL;
SELECT * FROM employees WHERE phone IS NOT NULL;
```

### IFNULL (MySQL 전용)
```sql
-- NULL이면 대체값 반환
SELECT name, IFNULL(phone, '없음') AS phone FROM employees;
```

### COALESCE (표준 SQL)
```sql
-- 첫 번째 non-NULL 값 반환
SELECT COALESCE(phone, email, '연락처 없음') AS contact FROM employees;
```

### NULLIF
```sql
-- 두 값이 같으면 NULL 반환, 다르면 첫 번째 값 반환
SELECT NULLIF(score, 0) FROM results;  -- 0이면 NULL로 처리 (0으로 나누기 방지)
```

> **Oracle 차이**: Oracle은 `NVL(val, default)` 사용. MySQL은 `IFNULL()`.

---

## 6. 정렬 (ORDER BY)

```sql
-- ASC(오름차순, 기본값), DESC(내림차순)
SELECT * FROM employees ORDER BY salary DESC;

-- 다중 정렬: 우선순위 순으로 나열
SELECT * FROM employees ORDER BY dept ASC, salary DESC;

-- NULL 정렬: MySQL에서 NULL은 가장 작은 값으로 취급
-- ASC → NULL이 제일 먼저, DESC → NULL이 제일 나중
```

---

## 7. 집계 함수 & GROUP BY & HAVING

### 집계 함수
| 함수 | 설명 |
|------|------|
| `COUNT(*)` | 전체 행 수 (NULL 포함) |
| `COUNT(col)` | col이 NULL이 아닌 행 수 |
| `COUNT(DISTINCT col)` | 고유값 수 |
| `SUM(col)` | 합계 |
| `AVG(col)` | 평균 |
| `MAX(col)` | 최대값 |
| `MIN(col)` | 최소값 |
| `GROUP_CONCAT(col)` | 그룹 내 값을 문자열로 연결 |

### GROUP BY
```sql
SELECT dept, COUNT(*) AS cnt, AVG(salary) AS avg_sal
FROM employees
GROUP BY dept;
```

### HAVING (GROUP BY 후 필터)
```sql
SELECT dept, SUM(salary) AS total
FROM employees
GROUP BY dept
HAVING SUM(salary) > 1000000;
```

> **WHERE vs HAVING**: WHERE는 그룹화 전 행 필터, HAVING은 그룹화 후 그룹 필터.

### GROUP_CONCAT
```sql
-- 그룹 내 값을 하나의 문자열로 합치기
SELECT dept, GROUP_CONCAT(name ORDER BY name SEPARATOR ', ') AS members
FROM employees
GROUP BY dept;
-- 결과: 'IT' | '김철수, 박영희, 이민수'
```

---

## 8. JOIN

### 한눈에 보기
| 타입 | 설명 |
|------|------|
| `INNER JOIN` | 양쪽 모두 일치하는 행만 |
| `LEFT JOIN` | 왼쪽 전체 + 오른쪽 일치 (없으면 NULL) |
| `RIGHT JOIN` | 오른쪽 전체 + 왼쪽 일치 (없으면 NULL) |
| `CROSS JOIN` | 카테시안 곱 (모든 조합) |
| `SELF JOIN` | 자기 자신과 조인 |

> MySQL은 `FULL OUTER JOIN` 직접 지원 안 함 → `LEFT JOIN UNION RIGHT JOIN`으로 구현.

### INNER JOIN
```sql
SELECT e.name, d.dept_name
FROM employees e
INNER JOIN departments d ON e.dept_id = d.id;
-- INNER 생략 가능: JOIN = INNER JOIN
```

### LEFT JOIN
```sql
-- 직원 전체 + 부서 정보 (부서 없는 직원도 포함)
SELECT e.name, d.dept_name
FROM employees e
LEFT JOIN departments d ON e.dept_id = d.id;
```

### RIGHT JOIN
```sql
SELECT e.name, d.dept_name
FROM employees e
RIGHT JOIN departments d ON e.dept_id = d.id;
```

### FULL OUTER JOIN (MySQL 구현)
```sql
SELECT * FROM A LEFT JOIN B ON A.id = B.id
UNION
SELECT * FROM A RIGHT JOIN B ON A.id = B.id;
```

### CROSS JOIN
```sql
SELECT * FROM colors CROSS JOIN sizes;
-- colors 3행 × sizes 4행 = 12행
```

### SELF JOIN
```sql
-- 직원과 매니저 조회
SELECT e.name AS employee, m.name AS manager
FROM employees e
LEFT JOIN employees m ON e.manager_id = m.id;

-- 연속 날짜 비교 (자주 출제!)
SELECT m1.measured_at AS today, m2.measured_at AS next_day
FROM measurements m1
LEFT JOIN measurements m2
  ON m2.measured_at = DATE_ADD(m1.measured_at, INTERVAL 1 DAY)
WHERE m2.pm10 > m1.pm10;
```

### 여러 테이블 조인
```sql
SELECT e.name, d.dept_name, l.city
FROM employees e
JOIN departments d ON e.dept_id = d.id
JOIN locations l ON d.loc_id = l.id;
```

### NATURAL JOIN
```sql
-- 같은 이름 컬럼을 자동으로 매칭 (비추: 의도치 않은 조인 위험)
SELECT name, course_id
FROM students NATURAL JOIN takes;
```

---

## 9. 서브쿼리

### WHERE 절 서브쿼리
```sql
-- 평균 급여보다 높은 직원
SELECT name FROM employees
WHERE salary > (SELECT AVG(salary) FROM employees);

-- IN과 함께
SELECT name FROM employees
WHERE dept_id IN (SELECT id FROM departments WHERE location = 'Seoul');
```

### FROM 절 서브쿼리 (인라인 뷰)
```sql
SELECT sub.dept, sub.avg_sal
FROM (
  SELECT dept, AVG(salary) AS avg_sal
  FROM employees
  GROUP BY dept
) sub
WHERE sub.avg_sal > 50000;
```
> MySQL에서는 FROM 절 서브쿼리에 반드시 **별칭(alias)** 필요!

### SELECT 절 서브쿼리 (스칼라 서브쿼리)
```sql
SELECT name,
  (SELECT dept_name FROM departments d WHERE d.id = e.dept_id) AS dept
FROM employees e;
```

### EXISTS / NOT EXISTS
```sql
-- 주문이 있는 고객
SELECT name FROM customers c
WHERE EXISTS (
  SELECT 1 FROM orders o WHERE o.customer_id = c.id
);

-- 주문이 없는 고객
SELECT name FROM customers c
WHERE NOT EXISTS (
  SELECT 1 FROM orders o WHERE o.customer_id = c.id
);
```

> **EXISTS vs IN**: 대량 데이터에서 EXISTS가 더 효율적. NOT IN은 NULL 주의.

### ALL / ANY(SOME)
```sql
-- 모든 IT 부서원보다 급여 높은 사람
SELECT name FROM employees
WHERE salary > ALL (SELECT salary FROM employees WHERE dept = 'IT');

-- IT 부서원 중 한 명보다라도 급여 높은 사람
SELECT name FROM employees
WHERE salary > ANY (SELECT salary FROM employees WHERE dept = 'IT');
```

---

## 10. 집합 연산

```sql
-- UNION: 합집합 (중복 제거)
SELECT name FROM employees
UNION
SELECT name FROM contractors;

-- UNION ALL: 합집합 (중복 포함, 더 빠름)
SELECT name FROM employees
UNION ALL
SELECT name FROM contractors;
```

> MySQL은 `INTERSECT`, `EXCEPT`를 **8.0.31+** 부터 지원.
> 이전 버전에서는 JOIN이나 NOT EXISTS로 대체.

```sql
-- INTERSECT 대안 (교집합)
SELECT a.name FROM tableA a
INNER JOIN tableB b ON a.name = b.name;

-- EXCEPT 대안 (차집합)
SELECT a.name FROM tableA a
LEFT JOIN tableB b ON a.name = b.name
WHERE b.name IS NULL;
```

---

## 11. 윈도우 함수

> **핵심**: 행을 그룹으로 묶지 않고, 각 행에 대해 계산. `OVER()` 절 사용.

### 순위 함수
```sql
SELECT name, dept, salary,
  ROW_NUMBER() OVER (ORDER BY salary DESC) AS rn,          -- 고유 번호 (동점 무시)
  RANK()       OVER (ORDER BY salary DESC) AS rnk,         -- 동점 시 같은 순위, 다음 건너뜀 (1,2,2,4)
  DENSE_RANK() OVER (ORDER BY salary DESC) AS dense_rnk    -- 동점 시 같은 순위, 안 건너뜀 (1,2,2,3)
FROM employees;
```

### PARTITION BY (그룹별 윈도우)
```sql
-- 부서별 급여 순위
SELECT name, dept, salary,
  RANK() OVER (PARTITION BY dept ORDER BY salary DESC) AS dept_rank
FROM employees;
```

### LAG / LEAD (이전/다음 행)
```sql
SELECT measured_at,
  pm10,
  LAG(pm10, 1)  OVER (ORDER BY measured_at) AS prev_pm10,  -- 이전 행 값
  LEAD(pm10, 1) OVER (ORDER BY measured_at) AS next_pm10   -- 다음 행 값
FROM measurements;

-- 3번째 인자: 기본값(NULL 대신)
LAG(pm10, 1, 0) OVER (ORDER BY measured_at)
```

### 누적합/이동평균
```sql
-- 누적 합계
SELECT date, amount,
  SUM(amount) OVER (ORDER BY date) AS running_total
FROM sales;

-- 이동 평균 (최근 3개)
SELECT date, amount,
  AVG(amount) OVER (ORDER BY date ROWS BETWEEN 2 PRECEDING AND CURRENT ROW) AS moving_avg
FROM sales;
```

### NTILE (N등분)
```sql
-- 급여 기준 4분위 나누기
SELECT name, salary,
  NTILE(4) OVER (ORDER BY salary DESC) AS quartile
FROM employees;
```

> **중요**: 윈도우 함수는 WHERE에서 사용 불가! → CTE나 서브쿼리로 감싸서 필터링.

```sql
-- 부서별 1등만 조회
SELECT * FROM (
  SELECT name, dept, salary,
    ROW_NUMBER() OVER (PARTITION BY dept ORDER BY salary DESC) AS rn
  FROM employees
) sub
WHERE rn = 1;
```

---

## 12. CTE (WITH)

> 가독성↑, 재사용 가능한 임시 결과 집합.

```sql
WITH dept_stats AS (
  SELECT dept, AVG(salary) AS avg_sal, COUNT(*) AS cnt
  FROM employees
  GROUP BY dept
)
SELECT * FROM dept_stats WHERE avg_sal > 50000;
```

### 여러 CTE 정의
```sql
WITH
  high_salary AS (
    SELECT * FROM employees WHERE salary > 80000
  ),
  dept_count AS (
    SELECT dept, COUNT(*) AS cnt FROM employees GROUP BY dept
  )
SELECT h.name, d.cnt
FROM high_salary h
JOIN dept_count d ON h.dept = d.dept;
```

### 재귀 CTE
```sql
-- 1부터 10까지 생성
WITH RECURSIVE numbers AS (
  SELECT 1 AS n
  UNION ALL
  SELECT n + 1 FROM numbers WHERE n < 10
)
SELECT * FROM numbers;

-- 연속 날짜 생성 (빈 날짜 채우기에 유용!)
WITH RECURSIVE dates AS (
  SELECT '2025-01-01' AS dt
  UNION ALL
  SELECT DATE_ADD(dt, INTERVAL 1 DAY) FROM dates WHERE dt < '2025-01-31'
)
SELECT * FROM dates;
```

---

## 13. CASE WHEN

```sql
-- 단순 조건 분기
SELECT name, salary,
  CASE
    WHEN salary >= 80000 THEN '고액'
    WHEN salary >= 50000 THEN '중간'
    ELSE '저액'
  END AS salary_grade
FROM employees;

-- 집계와 함께 (피벗 테이블)
SELECT dept,
  COUNT(CASE WHEN gender = 'M' THEN 1 END) AS male_cnt,
  COUNT(CASE WHEN gender = 'F' THEN 1 END) AS female_cnt
FROM employees
GROUP BY dept;

-- IF 함수 (CASE의 축약형, 2가지 분기만 가능)
SELECT name, IF(salary > 50000, '고액', '저액') AS grade
FROM employees;
```

---

## 14. 문자열 함수

| 함수 | 설명 | 예시 |
|------|------|------|
| `CONCAT(a, b, ...)` | 문자열 연결 | `CONCAT('Hello', ' ', 'World')` → `'Hello World'` |
| `CONCAT_WS(sep, a, b)` | 구분자로 연결 | `CONCAT_WS('-', '2025', '01', '19')` → `'2025-01-19'` |
| `SUBSTR(s, start, len)` | 부분 문자열 | `SUBSTR('Hello', 2, 3)` → `'ell'` |
| `LEFT(s, n)` | 왼쪽 n자 | `LEFT('Hello', 3)` → `'Hel'` |
| `RIGHT(s, n)` | 오른쪽 n자 | `RIGHT('Hello', 3)` → `'llo'` |
| `LENGTH(s)` | 바이트 수 | `LENGTH('가')` → `3` (UTF-8) |
| `CHAR_LENGTH(s)` | 문자 수 | `CHAR_LENGTH('가나다')` → `3` |
| `UPPER(s)` | 대문자 변환 | `UPPER('hello')` → `'HELLO'` |
| `LOWER(s)` | 소문자 변환 | `LOWER('HELLO')` → `'hello'` |
| `TRIM(s)` | 양쪽 공백 제거 | `TRIM('  hi  ')` → `'hi'` |
| `LTRIM(s)` | 왼쪽 공백 제거 | |
| `RTRIM(s)` | 오른쪽 공백 제거 | |
| `REPLACE(s, from, to)` | 문자열 치환 | `REPLACE('abc', 'b', 'x')` → `'axc'` |
| `REVERSE(s)` | 문자열 뒤집기 | `REVERSE('abc')` → `'cba'` |
| `LPAD(s, len, pad)` | 왼쪽 채우기 | `LPAD('5', 3, '0')` → `'005'` |
| `RPAD(s, len, pad)` | 오른쪽 채우기 | `RPAD('5', 3, '0')` → `'500'` |
| `INSTR(s, sub)` | 위치 찾기 | `INSTR('hello', 'lo')` → `4` |
| `LOCATE(sub, s)` | 위치 찾기 | `LOCATE('lo', 'hello')` → `4` |

> **Oracle 차이**: Oracle은 `||`로 연결, MySQL은 `CONCAT()` 사용.

---

## 15. 숫자 함수

| 함수 | 설명 | 예시 |
|------|------|------|
| `ROUND(n, d)` | 반올림 (d: 소수점 자릿수) | `ROUND(3.456, 2)` → `3.46` |
| `CEIL(n)` / `CEILING(n)` | 올림 | `CEIL(3.1)` → `4` |
| `FLOOR(n)` | 내림 | `FLOOR(3.9)` → `3` |
| `TRUNCATE(n, d)` | 버림 (d자리까지) | `TRUNCATE(3.456, 2)` → `3.45` |
| `ABS(n)` | 절대값 | `ABS(-5)` → `5` |
| `MOD(a, b)` | 나머지 | `MOD(10, 3)` → `1` |
| `POWER(a, b)` | 거듭제곱 | `POWER(2, 3)` → `8` |
| `SQRT(n)` | 제곱근 | `SQRT(16)` → `4` |
| `GREATEST(a, b, ...)` | 최대값 | `GREATEST(1, 5, 3)` → `5` |
| `LEAST(a, b, ...)` | 최소값 | `LEAST(1, 5, 3)` → `1` |

> **Oracle 차이**: Oracle은 `TRUNC()`, MySQL은 `TRUNCATE()`.

---

## 16. 날짜·시간 함수

### 현재 날짜/시간
```sql
SELECT NOW();            -- '2025-02-19 14:30:00' (DATETIME)
SELECT CURDATE();        -- '2025-02-19' (DATE만)
SELECT CURTIME();        -- '14:30:00' (TIME만)
SELECT CURRENT_TIMESTAMP; -- NOW()와 동일
```

### 날짜 추출
```sql
SELECT YEAR('2025-03-15');    -- 2025
SELECT MONTH('2025-03-15');   -- 3
SELECT DAY('2025-03-15');     -- 15
SELECT HOUR('14:30:00');      -- 14
SELECT MINUTE('14:30:00');    -- 30
SELECT SECOND('14:30:00');    -- 0
SELECT DAYOFWEEK('2025-03-15'); -- 요일 (1=일, 2=월, ..., 7=토)
SELECT DAYNAME('2025-03-15');   -- 'Saturday'
```

> **Oracle 차이**: Oracle은 `EXTRACT(YEAR FROM date)` 또는 `TO_CHAR(date, 'YYYY')`. MySQL은 `YEAR(date)` 직접 사용 가능.

### DATE_FORMAT (날짜 → 문자열)
```sql
SELECT DATE_FORMAT(NOW(), '%Y-%m-%d');          -- '2025-02-19'
SELECT DATE_FORMAT(NOW(), '%Y-%m-%d %H:%i:%s'); -- '2025-02-19 14:30:00'
SELECT DATE_FORMAT(NOW(), '%Y/%m/%d');          -- '2025/02/19'
SELECT DATE_FORMAT(NOW(), '%H시 %i분');          -- '14시 30분'
```

| 포맷 | 설명 | 예시 |
|------|------|------|
| `%Y` | 4자리 연도 | 2025 |
| `%y` | 2자리 연도 | 25 |
| `%m` | 월 (01-12) | 03 |
| `%d` | 일 (01-31) | 15 |
| `%H` | 시 (00-23) | 14 |
| `%h` | 시 (01-12) | 02 |
| `%i` | 분 (00-59) | 30 |
| `%s` | 초 (00-59) | 00 |
| `%W` | 요일명 | Saturday |

> **Oracle 차이**: Oracle은 `TO_CHAR(date, 'YYYY-MM-DD')` 사용.

### STR_TO_DATE (문자열 → 날짜)
```sql
SELECT STR_TO_DATE('2025-03-15', '%Y-%m-%d');
SELECT STR_TO_DATE('15/03/2025', '%d/%m/%Y');
```

> **Oracle 차이**: Oracle은 `TO_DATE('2025-03-15', 'YYYY-MM-DD')` 사용.

### 날짜 연산
```sql
-- 더하기
SELECT DATE_ADD('2025-01-01', INTERVAL 7 DAY);    -- '2025-01-08'
SELECT DATE_ADD('2025-01-01', INTERVAL 1 MONTH);   -- '2025-02-01'
SELECT DATE_ADD('2025-01-01', INTERVAL 1 YEAR);    -- '2026-01-01'
SELECT DATE_ADD(NOW(), INTERVAL 3 HOUR);

-- 빼기
SELECT DATE_SUB('2025-01-31', INTERVAL 1 MONTH);  -- '2024-12-31'
SELECT DATE_SUB(NOW(), INTERVAL 30 DAY);

-- 날짜 차이
SELECT DATEDIFF('2025-03-01', '2025-01-01');       -- 59 (일 단위)
SELECT TIMESTAMPDIFF(MONTH, '2025-01-01', '2025-03-01'); -- 2
SELECT TIMESTAMPDIFF(HOUR, '2025-01-01 00:00:00', '2025-01-01 12:30:00'); -- 12
-- TIMESTAMPDIFF 단위: SECOND, MINUTE, HOUR, DAY, WEEK, MONTH, QUARTER, YEAR

-- 시간 차이
SELECT TIMEDIFF('16:30:00', '14:00:00'); -- '02:30:00'
```

> **Oracle 차이**: Oracle은 날짜에 숫자 직접 덧셈 (`sysdate + 1`). MySQL은 `DATE_ADD()` 사용.

### 자주 쓰는 날짜 패턴
```sql
-- 오늘 날짜의 연월만
SELECT DATE_FORMAT(NOW(), '%Y-%m') AS year_month;

-- 이번 달 1일
SELECT DATE_FORMAT(NOW(), '%Y-%m-01');

-- 시간대별 그룹핑 (0~23시)
SELECT HOUR(created_at) AS hour, COUNT(*)
FROM orders
GROUP BY HOUR(created_at)
ORDER BY hour;

-- 요일별 그룹핑
SELECT DAYOFWEEK(created_at) AS dow, COUNT(*)
FROM orders
GROUP BY dow;
```

---

## 17. 형변환

```sql
-- CAST
SELECT CAST('123' AS SIGNED);           -- 정수로 변환
SELECT CAST('2025-01-01' AS DATE);      -- 날짜로 변환
SELECT CAST(3.14 AS CHAR);             -- 문자열로 변환
SELECT CAST(salary AS DECIMAL(10,2));   -- 정밀 소수

-- CONVERT (MySQL 전용 문법)
SELECT CONVERT('123', SIGNED);
SELECT CONVERT('2025-01-01', DATE);
```

| 타입 | 설명 |
|------|------|
| `SIGNED` | 부호 있는 정수 |
| `UNSIGNED` | 부호 없는 정수 |
| `DECIMAL(M,D)` | 정밀 소수 |
| `CHAR` | 문자열 |
| `DATE` | 날짜 |
| `DATETIME` | 날짜+시간 |
| `TIME` | 시간 |

> **Oracle 차이**: Oracle은 `TO_NUMBER()`, `TO_CHAR()`, `TO_DATE()` 사용.

---

## 18. LIMIT & OFFSET

```sql
-- 상위 N개
SELECT * FROM employees ORDER BY salary DESC LIMIT 5;

-- OFFSET: 건너뛸 행 수 (0부터 시작)
SELECT * FROM employees ORDER BY salary DESC LIMIT 5 OFFSET 10;
-- = LIMIT 10, 5  (offset, count 순서 주의!)

-- 두 번째로 높은 급여
SELECT DISTINCT salary FROM employees ORDER BY salary DESC LIMIT 1 OFFSET 1;
```

> **Oracle 차이**: Oracle은 `ROWNUM` 또는 12c부터 `FETCH FIRST N ROWS ONLY`. MySQL은 `LIMIT`.

---

## 19. 변수

```sql
-- 변수 선언 & 할당
SET @start = 1;
SET @end = 10;

SELECT * FROM employees WHERE id BETWEEN @start AND @end;

-- SELECT에서 변수 할당 시 := 사용
SELECT @rownum := @rownum + 1 AS rn, name
FROM employees, (SELECT @rownum := 0) r;
```

> MySQL 8.0 이상에서는 윈도우 함수 `ROW_NUMBER()`를 쓰는 게 더 깔끔.

---

## 20. 기타 자주 쓰이는 함수

### DISTINCT
```sql
SELECT DISTINCT city FROM customers;
SELECT COUNT(DISTINCT city) FROM customers;
```

### WITH ROLLUP (소계/합계)
```sql
SELECT dept, COUNT(*) AS cnt
FROM employees
GROUP BY dept WITH ROLLUP;
-- 마지막 행에 전체 합계가 추가됨
```

### ANY_VALUE (ONLY_FULL_GROUP_BY 대응)
```sql
-- GROUP BY에 포함 안 된 컬럼 조회 시
SELECT dept, ANY_VALUE(name), COUNT(*)
FROM employees
GROUP BY dept;
```

### 여러 값 중 선택 (ELT, FIELD)
```sql
SELECT ELT(2, '일', '월', '화', '수');  -- '월' (N번째 값 반환)
SELECT FIELD('월', '일', '월', '화');     -- 2 (위치 반환)
```

---

## 부록: Oracle → MySQL 주요 차이점 요약

| 기능 | Oracle | MySQL |
|------|--------|-------|
| 문자열 연결 | `\|\|` | `CONCAT()` |
| NULL 대체 | `NVL()` | `IFNULL()` |
| 날짜 변환 | `TO_DATE()` / `TO_CHAR()` | `STR_TO_DATE()` / `DATE_FORMAT()` |
| 숫자 변환 | `TO_NUMBER()` | `CAST(... AS SIGNED)` |
| 버림 | `TRUNC()` | `TRUNCATE()` |
| 현재 날짜 | `SYSDATE` | `NOW()` / `CURDATE()` |
| 행 제한 | `ROWNUM` / `FETCH FIRST` | `LIMIT` |
| 시퀀스 | `SEQUENCE` | `AUTO_INCREMENT` |
| 빈 테이블 조회 | `FROM DUAL` | `FROM DUAL` (생략 가능) |
| 문자열 함수 | `SUBSTR()` | `SUBSTR()` (동일) |
| 날짜 연산 | `date + 숫자` | `DATE_ADD()` |
| DECODE | `DECODE()` | `CASE WHEN` 또는 `IF()` |
| NVL2 | `NVL2(a, b, c)` | `IF(a IS NOT NULL, b, c)` |

---

## 부록: 코딩테스트 빈출 패턴

### 1. N번째 큰/작은 값
```sql
SELECT DISTINCT salary FROM employees
ORDER BY salary DESC LIMIT 1 OFFSET N-1;
```

### 2. 그룹별 최대/최소 행 전체 조회
```sql
WITH ranked AS (
  SELECT *, ROW_NUMBER() OVER (PARTITION BY dept ORDER BY salary DESC) AS rn
  FROM employees
)
SELECT * FROM ranked WHERE rn = 1;
```

### 3. 연속 날짜 없는 날 찾기
```sql
WITH RECURSIVE all_dates AS (
  SELECT MIN(dt) AS dt FROM events
  UNION ALL
  SELECT DATE_ADD(dt, INTERVAL 1 DAY) FROM all_dates
  WHERE dt < (SELECT MAX(dt) FROM events)
)
SELECT a.dt FROM all_dates a
LEFT JOIN events e ON a.dt = e.dt
WHERE e.dt IS NULL;
```

### 4. 누적 합계
```sql
SELECT date, amount,
  SUM(amount) OVER (ORDER BY date) AS cumulative
FROM sales;
```

### 5. 전일 대비 증감
```sql
SELECT date, amount,
  amount - LAG(amount, 1) OVER (ORDER BY date) AS diff
FROM sales;
```

### 6. 중복 데이터 찾기
```sql
SELECT email, COUNT(*) AS cnt
FROM users
GROUP BY email
HAVING COUNT(*) > 1;
```

### 7. 자기 자신 제외 조인
```sql
SELECT a.name, b.name
FROM employees a
JOIN employees b ON a.dept = b.dept AND a.id <> b.id;
```

### 8. 피벗 (행 → 열)
```sql
SELECT year,
  SUM(CASE WHEN month = 1 THEN revenue ELSE 0 END) AS jan,
  SUM(CASE WHEN month = 2 THEN revenue ELSE 0 END) AS feb,
  SUM(CASE WHEN month = 3 THEN revenue ELSE 0 END) AS mar
FROM sales
GROUP BY year;
```
