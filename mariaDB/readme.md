# mariaDB 학습

* mariaDB에 대한 설치부터 활용을 학습하는 디렉토리입니다.

## 설치 

* 다운로드 : https://mariadb.org/
* 설치 버전 : mariadb-10.11.7

## sql 구성요소

* SELECT: 데이터를 조회합니다.
  ```
  SELECT name FROM students;
  ```
  - 위의 쿼리는 students 테이블에서 name 열의 모든 값을 선택합니다.
    
* FROM: 조회할 테이블을 지정합니다.
  ```
  SELECT * FROM students;
  ```
  - 위의 쿼리는 students 테이블의 모든 열을 선택합니다.
* INNER JOIN: 두 테이블에서 일치하는 행을 결합합니다.
  ```
  SELECT students.name, grades.grade 
  FROM students 
  INNER JOIN grades ON students.id = grades.student_id;
  ```
  - 위의 쿼리는 students 테이블과 grades 테이블을 id와 student_id가 일치하는 행으로 결합하고, name과 grade를 선택합니다.
* LEFT JOIN: 왼쪽 테이블의 모든 행과 오른쪽 테이블의 일치하는 행을 결합합니다.
  ```
  SELECT students.name, grades.grade 
  FROM students 
  LEFT JOIN grades ON students.id = grades.student_id;
  ```
  - 위의 쿼리는 students 테이블의 모든 행과 grades 테이블의 일치하는 행을 결합하고, name과 grade를 선택합니다.
* WHERE: 조회할 행의 조건을 지정합니다.
  ```
  SELECT * FROM students WHERE age > 18;
  ```
  - 위의 쿼리는 students 테이블에서 age가 18 초과인 행을 선택합니다.
* GROUP BY: 결과를 그룹화하는 열을 지정합니다.
  ```
  SELECT age, COUNT(*) 
  FROM students 
  GROUP BY age;
  ```
  - 위의 쿼리는 students 테이블에서 age 열로 그룹화하고, 각 나이별 학생 수를 계산합니다.
* ORDER BY: 결과를 정렬하는 열을 지정합니다.
  ```
  SELECT * FROM students ORDER BY name ASC;
  ```
  - 위의 쿼리는 students 테이블의 모든 행을 name 열의 값에 따라 오름차순으로 정렬합니다.
* CASE: 조건에 따라 다른 값을 반환합니다.
  ```
  SELECT name, 
  CASE 
    WHEN age >= 20 THEN 'adult'
    ELSE 'minor'
  END AS age_group
  FROM students;
  ```
  - 위의 쿼리는 students 테이블에서 name을 선택하고, age가 20 이상이면 ‘adult’, 그렇지 않으면 'minor’를 age_group으로 반환합니다.
* 집계 함수: 여러 행의 값을 하나로 요약합니다.
  ```
  SELECT AVG(age) FROM students;
  ```
  - 위의 쿼리는 students 테이블에서 age의 평균을 계산합니다.
* WITH: 하나 이상의 임시 결과 집합을 정의하는 데 사용됩니다. 이 결과 집합은 단일 SELECT 문에서 여러 번 사용될 수 있습니다.
  ```
  WITH e01 AS (SELECT stdid , ROUND(SUM(clsscr),1) sj01 FROM evtscore01  GROUP BY stdid)
  ```
  - 위의 쿼리는 evtscore01 테이블에서 stdid로 그룹화하고, 각 stdid별 clsscr의 합계를 반올림하여 sj01로 반환하는 e01이라는 임시 결과 집합을 정의합니다.
* CASE: 조건에 따라 다른 값을 반환합니다.
  ```
  case when typgubun = '그룹 1' then 1
     when typgubun = '그룹 2' then 2
     ELSE 3 END tg
  ```
  - 위의 쿼리는 typgubun이 '그룹 1’이면 1을, '그룹 2’이면 2를, 그 외의 경우에는 3을 tg로 반환합니다.
* IFNULL: 첫 번째 인수가 NULL이 아니면 첫 번째 인수를 반환하고, 첫 번째 인수가 NULL이면 두 번째 인수를 반환합니다.
  ```
  IFNULL(e01.sj01,0) + IFNULL(e02.sj02,0) sj
  ```
  - 위의 쿼리는 e01.sj01이 NULL이 아니면 e01.sj01을, NULL이면 0을 반환하고, e02.sj02가 NULL이 아니면 e02.sj02를, NULL이면 0을 반환한 후 두 값을 더하여 sj로 반환합니다.
* RANK() OVER: 특정 열의 순위를 계산합니다. PARTITION BY는 순위를 계산할 때 그룹을 나누는 열을 지정하고, ORDER BY는 순위를 계산할 때 정렬 순서를 지정합니다.
  ```
  RANK() OVER (PARTITION BY typgubun ORDER BY (IFNULL(e01.sj01,0) +IFNULL(e02.sj02,0)) DESC) rk
  ```
  - 위의 쿼리는 typgubun으로 그룹을 나눈 후, 각 그룹 내에서 (IFNULL(e01.sj01,0) + IFNULL(e02.sj02,0))의 값에 따라 내림차순으로 순위를 계산하고, 그 순위를 rk로 반환합니다.
* 테이블 백업 :  mstusr 테이블의 모든 데이터를 복사하여 mstusr_bak라는 새 테이블을 생성합니다
  ```
  CREATE TABLE mstusr_bak
  AS
  SELECT * FROM mstusr;
  ```
  - 위의 쿼리를 실행하면, ddsusr 테이블의 모든 열과 데이터가 mstusr_bak 테이블에 복사됩니다. 이렇게 하면 원본 테이블(mstusr)을 변경하지 않고도 데이터를 안전하게 백업하거나 다른 작업을 수행할 수 있습니다.

