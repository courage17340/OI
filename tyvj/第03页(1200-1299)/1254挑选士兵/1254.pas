var
  a,d:array[1..31000] of longint;
  len,i,j,k,n,l,r,mid:longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  len:=1;
  d[1]:=a[1];
  for i:=2 to n do
    if a[i]>=d[len] then begin inc(len);d[len]:=a[i];end
      else
        begin
          l:=1;r:=len;
          while l<r do
            begin
              mid:=(l+r) shr 1;
              if a[i]<d[mid] then r:=mid else l:=mid+1;
            end;
          d[l]:=a[i];
        end;
  writeln(len);
  readln;readln;
end.
