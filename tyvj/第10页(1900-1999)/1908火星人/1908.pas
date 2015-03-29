var
  n,m:longint;
  a:array[0..10000] of longint;
procedure init;
var
  i:longint;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  readln(m);
  for i:=1 to n do read(a[i]);
end;

procedure work;
var
  i,j,t,k:longint;
begin
  for k:=1 to m do
    begin
      i:=n-1;
      while (i>0)and(a[i]>a[i+1]) do i:=i-1;
      j:=n;
      while a[j]<a[i] do j:=j-1;
      t:=a[i];
      a[i]:=a[j];
      a[j]:=t;
      i:=i+1;
      j:=n;
      while i<j do
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
          i:=i+1;
          j:=j-1;
        end;
    end;
  write(a[1]);
  for i:=2 to n do write(' ',a[i]);
end;

begin
  init;
  work;
end.