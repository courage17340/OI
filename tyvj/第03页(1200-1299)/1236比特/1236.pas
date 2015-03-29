const n=20;
var
  a:array[0..n] of 0..1;
  i,j,k,num,ans:longint;
procedure pan;
var i:longint;
begin
  for i:=1 to n-1 do
    if a[i]=1 then if a[i+1]=1 then inc(ans);
end;
begin
  read(num);
  ans:=0;
  fillchar(a,sizeof(a),0);
  for k:=1 to num do
    begin
      i:=n;
      while a[i]=1 do i:=i-1;
      a[i]:=1;
      for j:=i+1 to n do a[j]:=0;
      pan;
    end;
  writeln(ans);
end.