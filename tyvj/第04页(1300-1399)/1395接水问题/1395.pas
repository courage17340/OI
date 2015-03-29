var
  a:array[0..100] of longint;
  b:array[1..10000] of longint;
  m,n,i,j,ans,k:longint;
begin
  readln(n,m);
  for i:=1 to n do read(b[i]);
  fillchar(a,sizeof(a),0);
  for i:=1 to m do a[i]:=b[i];
  j:=m;
  while j<n do
    begin
      inc(j);
      ans:=maxlongint;
      for i:=1 to m do if a[i]<ans then begin ans:=a[i];k:=i;end;
      a[k]:=a[k]+b[j];
    end;
  ans:=0;
  for i:=1 to m do if ans<a[i] then ans:=a[i];
  writeln(ans);
end.