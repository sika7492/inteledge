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


