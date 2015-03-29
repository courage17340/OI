var
  a,sum:array[0..101,0..101] of longint;
  i,j,n,m1,m2,p,k:longint;
function max(a,b:longint):longint;
begin
  max:=a;if a<b then max:=b;
end;
begin
  m1:=0;m2:=0;
  read(n);
  fillchar(sum,sizeof(sum),0);
  for i:=1 to n do for j:=1 to n do
    begin
      read(a[i,j]);
      sum[i,j]:=sum[i-1,j]+sum[i,j-1]-sum[i-1,j-1]+a[i,j];
    end;
  for i:=1 to n do for j:=1 to n do
    for k:=0 to n-max(i,j) do
      begin
        p:=sum[i+k,j+k]-sum[i-1,j+k]-sum[i+k,j-1]+sum[i-1,j-1];
        if p>m1 then m1:=p;
      end;
  for i:=1 to n do for j:=1 to n do
    for k:=0 to n-max(i,j) do
      begin
        p:=sum[i+k,j+k]-sum[i-1,j+k]-sum[i+k,j-1]+sum[i-1,j-1];
        if p<m2 then m2:=p;
      end;
  writeln(m1);
  writeln(-m2);
end.
