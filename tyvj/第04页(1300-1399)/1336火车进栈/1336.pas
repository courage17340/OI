var
  i,j,n,k,temp,num:longint;
  total:longint;
  a,f:array[0..100] of integer;
procedure pan;
var i,j,x:longint;
begin
  fillchar(f,sizeof(f),0);
  j:=0;x:=0;
  for i:=1 to n do
    if f[j]=a[i] then dec(j)
      else
        begin
          while x<a[i] do begin inc(x);inc(j);f[j]:=x;end;
          if f[j]=a[i] then dec(j) else exit;
        end;
  inc(num);
  for i:=1 to n do write(a[i]);
  writeln;
end;
begin
  num:=0;
  read(n);
  for i:=1 to n do a[i]:=i;
  total:=1;
  if n<10 then for i:=1 to n do total:=total*i else total:=maxlongint;
  for k:=1 to total do
    begin
      pan;
      if num=20 then halt;
      i:=n-1;
      while (i>0)and(a[i]>a[i+1]) do i:=i-1;
      j:=n;
      while a[j]<a[i] do j:=j-1;
      temp:=a[i];
      a[i]:=a[j];
      a[j]:=temp;
      i:=i+1;
      j:=n;
      while i<j do
        begin
          temp:=a[i];
          a[i]:=a[j];
          a[j]:=temp;
          i:=i+1;
          j:=j-1;
        end;
    end;
end.