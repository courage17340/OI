var
  a,f:array[0..1000000] of longint;
  i,j,m,n,ans,m1,m2,d1,d2,t:longint;
begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do f[i]:=a[i];
  m1:=maxlongint;
  for i:=1 to m do if m1>a[i] then begin m1:=a[i];d1:=i;end;
  m2:=maxlongint;
  for i:=1 to m do if (m2>a[i])and(i<>d1) then begin m2:=a[i];d2:=i;end;
  for i:=m+1 to n do
    begin
      f[i]:=m1+a[i];
      if m2>f[i] then begin m2:=f[i];d2:=i;end;
      if i-m=d1 then
        begin
          d1:=d2;m1:=m2;m2:=maxlongint;
          for j:=i-m+1 to i do if (m2>f[j])and(j<>d1) then begin m2:=f[j];d2:=j;end;
        end;
      if i-m=d2 then
        begin
          m2:=maxlongint;
          for j:=i-m+1 to i do if (m2>f[j])and(j<>d1) then begin m2:=f[j];d2:=j;end;
        end;
    end;
  ans:=maxlongint;
  for i:=n-m+1 to n do
    if ans>f[i] then ans:=f[i];
  writeln(ans);
  readln;readln;
end.
