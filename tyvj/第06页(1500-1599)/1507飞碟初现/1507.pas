var
 a:array[0..50000] of longint;
 L,r,i,j,n,ans:longint;
 ch:char;
function f(ch:char):longint;
begin
 case ch of
    'G':exit(1);
    'A':exit(2);
    'T':exit(3);
    'C':exit(4);
 end;
end;
begin
  readln(n);
  a[0]:=0;a[n+1]:=0;
  for i:=1 to n do
    begin
      read(ch);
      a[i]:=f(ch);
    end;
  ans:=0;
  for i:=1 to n-1 do
    begin
      L:=i;r:=i+1;
      while a[L]+a[r]=5 do begin inc(r);dec(L);end;
      dec(r);inc(L);
      j:=r-L+1;
      if ans<j then ans:=j;
    end;
  writeln(ans);
end.