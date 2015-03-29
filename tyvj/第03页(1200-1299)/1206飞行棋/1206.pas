var
  n,i,j:longint;
  ans:longint;
  a,s:array[0..40] of longint;
function c(x:longint):longint;
begin
  exit(x*(x-1) shr 1);
end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(s,sizeof(s),0);
  read(n);
  for i:=1 to n do begin read(a[i]);a[i+n]:=a[i];end;
  for i:=1 to n*2 do s[i]:=s[i-1]+a[i];
  ans:=0;
  for i:=1 to n do
    for j:=i to n+i-1 do
      if s[j]-s[i-1]=s[n] shr 1 then inc(ans);
  ans:=c(ans shr 1);
  writeln(ans);
end.
